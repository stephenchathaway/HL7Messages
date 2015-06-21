#include "hl7Field.h"

QStringList hl7Field::EncodingChars = QStringList() << "^" << "~" << "\"" << "&";

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
    parseField();
}

QVector<hl7Field> hl7Field::fields()
{
    return m_fields;
}

bool hl7Field::parseField()
{
    if (m_name.contains("Encoding")) return true;

    foreach (QString tLoopChar, EncodingChars)
    {
        if (m_value.contains(tLoopChar))
        {
            QStringList tSplit = m_value.split(tLoopChar);
            if (tSplit.length() != 0)
            {
                for (int x = 0; x < tSplit.length(); x++)
                {
                    hl7Field tField = hl7Field("UNK", tSplit[x]);
                    m_fields << tField;
                }
            }
        }
    }
}

QTreeWidgetItem* hl7Field::getTreeItem()
{
    QTreeWidgetItem *tRetval = new QTreeWidgetItem();

    tRetval->setText(0, value() + (fields().length() != 0 ? "(" + QString::number(fields().length()) + ")" : ""));
    tRetval->setText(1, name());

    for (int x = 0; x < fields().length(); x++)
        tRetval->addChild(fields()[x].getTreeItem());

    return tRetval;
}
