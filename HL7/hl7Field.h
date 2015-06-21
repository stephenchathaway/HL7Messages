#ifndef HL7FIELD_H
#define HL7FIELD_H

#define HL7_MESSAGE_HEADER                  "MSH"
#define HL7_MESSAGE_HEADER_ENC_CHAR         "^~\&"

#include <QObject>

class hl7Field
{
public:
    hl7Field();
    hl7Field(const QString &pName, const QString &pValue);

    QString name() const;
    void setName(const QString &pName);

    QString value() const;
    void setValue(const QString &pValue);

private:
    QString m_name;
    QString m_value;

    bool parseField(const QStringList &pSeperators);

};

#endif // HL7FIELD_H
