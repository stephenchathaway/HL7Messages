#ifndef HL7MESSAGE_H
#define HL7MESSAGE_H

#include <QObject>
#include <QVector>
#include <QStringList>

#include <hl7Field.h>

class hl7Message
{
public:
    hl7Message();
    hl7Message(const QString &pMessage);

    QVector<hl7Field> fields();

    QString message();
    void setMessage(const QString &pMessage);
    bool parseMessage();

    QString segmentID() const;
    void setSegmentID(const QString &pID);

    hl7Field* fieldSeperator();
    void setFieldSeperator(hl7Field *pFieldSeperator);

    QVector<hl7Field> patientIDs();

    QTreeWidgetItem* getTreeWidgetItem();

private:
    hl7Field            *m_fieldSeperator;
    QString             m_rawMessage;
    QStringList         m_parsedSplit;
    QString             m_segmentID;

    QVector<hl7Field>   m_patientIDs;

    QVector<QString>    m_SIDs;
    QVector<QString>    m_MSH_fields;
    QVector<QString>    m_EVN_fields;
    QVector<QString>    m_PID_fields;
    QVector<QString>    m_OBR_fields;
    QVector<QString>    m_OBX_fields;
    QVector<QString>    m_PV1_fields;
    QVector<QString>    m_PID_patientID_fields;

    QVector<hl7Field>   m_fields;

    void setSegmentIDs();
    void setFields();
    void parseFields(QString pParsed, QVector<QString> pFields);
    void getPID();
    void parseMessageHeader(QString pParsed);
    void parseEventType(QString pParsed);
    void parsePatientIdentification(QString pParsed);
    void parseObservationRequest(QString pParsed);
};

#endif // HL7MESSAGE_H
