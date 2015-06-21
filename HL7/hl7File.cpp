#include "hl7File.h"

#include <QDebug>

hl7File::hl7File()
{

}

hl7File::hl7File(const QFileInfo &pFileInfo)
{
    setFileInfo(pFileInfo);
}

QFileInfo hl7File::fileInfo() const
{
    return m_fileInfo;
}

void hl7File::setFileInfo(const QFileInfo &pInfo)
{
    m_fileInfo = pInfo;
    parseMessages();
}

QVector<hl7Message> hl7File::messages()
{
    return m_messages;
}

bool hl7File::parseMessages()
{
    QFile       tFile;
    QTextStream tStream;
    QString     tString;

    tFile.setFileName(m_fileInfo.filePath());
    tFile.open(QIODevice::ReadOnly);

    if (!tFile.isOpen())
    {
        return false;
    }
    else
    {
        tStream.setDevice(&tFile);
        tString = tStream.readAll();

        QList<QString> tMessages = tString.split("\n");
        foreach (QString tLoopString, tMessages)
        {           
            if (tLoopString != "")
            {
                if (tLoopString.contains("OBX"))
                {
                    int tIndex = tLoopString.indexOf("OBX");
                    while (tIndex != -1)
                    {
                        int tInt = tLoopString.indexOf("OBX", tIndex + 3);

                        qDebug() << "tIndex: " << QString::number(tIndex) << " tInt: " << QString::number(tInt);
                        tString = tLoopString.mid(tIndex, tInt);
                        qDebug() << tString;
                        m_messages << hl7Message(tString);
                        m_messages.last().parseMessage();

                        tIndex = tInt;
                    }
                }
                else
                {
                    hl7Message tMessage = hl7Message(tLoopString.trimmed());
                    tMessage.parseMessage();

                    m_messages << tMessage;

                    if (tMessage.segmentID() == "MSH")
                    {
                        hl7Field tField = tMessage.fields()[1];
                        for (int x = 0; x < tField.value().length(); x++)
                            m_seperators.append(QString(tField.value()[x]));
                    }
                }
            }
        }
    }

    return true;
}

QStringList hl7File::seperators() const
{
    return m_seperators;
}
