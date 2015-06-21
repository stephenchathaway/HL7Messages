#ifndef HL7FILE_H
#define HL7FILE_H

#include <QObject>
#include <QVector>
#include <QFileInfo>
#include <QTextStream>

#include <hl7Message.h>

class hl7File
{
public:
    hl7File();
    hl7File(const QFileInfo &pFileInfo);

    bool parseMessages();

    QFileInfo fileInfo() const;
    void setFileInfo(const QFileInfo &pInfo);

    QVector<hl7Message> messages();
    QStringList seperators() const;

private:
    QFileInfo           m_fileInfo;
    QVector<hl7Message> m_messages;
    hl7Field            *m_endcodingChars;
    QStringList         m_seperators;

};

#endif // HL7FILE_H
