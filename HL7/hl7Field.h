#ifndef HL7FIELD_H
#define HL7FIELD_H

#define HL7_MESSAGE_HEADER                  "MSH"
#define HL7_MESSAGE_HEADER_ENC_CHAR         "^~\&"

#include <QObject>
#include <QVector>
#include <QStringList>
#include <QTreeWidgetItem>

class hl7Field
{
public:
    static QStringList EncodingChars;

    hl7Field();
    hl7Field(const QString &pName, const QString &pValue);

    QString name() const;
    void setName(const QString &pName);

    QString value() const;
    void setValue(const QString &pValue);

    QVector<hl7Field> fields();

    QTreeWidgetItem* getTreeItem();

private:
    QString m_name;
    QString m_value;

    bool parseField();

    QVector<hl7Field> m_fields;

};

#endif // HL7FIELD_H
