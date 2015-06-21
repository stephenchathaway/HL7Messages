#include "hl7Field.h"

hl7Field::hl7Field()
{
}

hl7Field::hl7Field(const QString &pName, const QString &pValue)
{
    setName(pName);
    setValue(pValue);
}

QString hl7Field::name() const
{
    return m_name;
}

void hl7Field::setName(const QString &pName)
{
    m_name = pName;
}

QString hl7Field::value() const
{
    return m_value;
}

void hl7Field::setValue(const QString &pValue)
{
    m_value = pValue;
}

bool hl7Field::parseField(const QStringList &pSeperators)
{

}
