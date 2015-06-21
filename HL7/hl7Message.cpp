#include "hl7Message.h"

#include <QDebug>

hl7Message::hl7Message()
{
    setSegmentIDs();
    setFields();
}

hl7Message::hl7Message(hl7File *pParent, const QString &pMessage)
{
    m_parent = pParent;
    setSegmentIDs();
    setFields();
    setMessage(pMessage);
}

void hl7Message::setSegmentIDs()
{
    m_SIDs << "MSH"
           << "EVN"
           << "PID"
           << "OBR"
           << "OBX"
           << "PV1";
}

void hl7Message::setFields()
{
    m_MSH_fields << "Sending Application"
                 << "Sending Facility"
                 << "Receiving Application"
                 << "Receiving Facility"
                 << "Date/Time of Message"
                 << "Security"
                 << "Message Type"
                 << "Message Control Id"
                 << "Processing Id"
                 << "Version Id"
                 << "Sequence Number"
                 << "Continuation Pointer"
                 << "Accept Acknowledgement Type"
                 << "Application Acknowledgement Type"
                 << "Country Code"
                 << "Character Set"
                 << "Principal Language of Message";

    m_EVN_fields << "Event Type Code"
                 << "Recorded Date/Time"
                 << "Date/Time Planned Event"
                 << "Event Reason Code"
                 << "Operator ID"
                 << "Event Occurred";

    m_PID_fields << "Set ID – Patient ID"
                 << "Patient ID (External ID)"
                 << "Patient ID (Internal ID)"
                 << "Alternate Patient ID – PID"
                 << "Patient Name"
                 << "Mother’s Maiden Name"
                 << "Date/Time of Birth"
                 << "Sex"
                 << "Patient Alias"
                 << "Race"
                 << "Patient Address"
                 << "Country Code"
                 << "Phone Number – Home"
                 << "Phone Number – Business"
                 << "Primary Language"
                 << "Marital Status"
                 << "Religion"
                 << "Patient Account Number"
                 << "SSN Number – Patient"
                 << "Driver’s License Number - Patient"
                 << "Mother’s Identifier"
                 << "Ethnic Group"
                 << "Birth Place"
                 << "Multiple Birth Indicator"
                 << "Birth Order"
                 << "Citizenship"
                 << "Veterans Military Status"
                 << "Nationality"
                 << "Patient Death Date and Time"
                 << "Patient Death Indicator";

    m_OBR_fields << "Set ID"
                 << "Placer Order Number"
                 << "Filler Order Number"
                 << "Universal Service ID"
                 << "Priority"
                 << "Requested Date/time"
                 << "Observation Date/Time"
                 << "Observation End Date/Time"
                 << "Collection Volume"
                 << "Collector Identifier"
                 << "Specimen Action Code"
                 << "Danger Code"
                 << "Relevant Clinical Info."
                 << "Specimen Received Date/Time"
                 << "Specimen Source"
                 << "Ordering Provider"
                 << "Order Callback Phone Number"
                 << "Placer field 1"
                 << "Placer field 2"
                 << "Filler Field 1"
                 << "Filler Field 2"
                 << "Results Rpt/Status Chng - Date/Time"
                 << "Charge to Practice"
                 << "Diagnostic Serv Sect ID"
                 << "Result Status"
                 << "Parent Result"
                 << "Quantity/Timing"
                 << "Result Copies To"
                 << "Parent"
                 << "Transportation Mode"
                 << "Reason for Study"
                 << "Principal Result Interpreter"
                 << "Assistant Result Interpreter"
                 << "Technician"
                 << "Transcriptionist"
                 << "Scheduled Date/Time"
                 << "Number of Sample Containers"
                 << "Transport Logistics of Collected Sample"
                 << "Collector’s Comment"
                 << "Transport Arrangement Responsibility"
                 << "Transport Arranged"
                 << "Escort Required"
                 << "Planned Patient Transport Comment";

    m_OBX_fields << "Set ID – Obx"
                 << "Value Type"
                 << "Observation Identifier"
                 << "Observation Sub-Id"
                 << "Observation Value"
                 << "Units"
                 << "Reference Range"
                 << "Abnormal Flags"
                 << "Probability"
                 << "Nature of Abnormal Test"
                 << "Observ Result Status"
                 << "Data Last Obs Normal Values"
                 << "User Defined Access Checks"
                 << "Date/Time of the Observation"
                 << "Producer’s Id"
                 << "Responsible Observer"
                 << "Observation Method";

    m_PV1_fields << "Set ID - PV1"
                 << "Patient Class"
                 << "Assigned Patient Location"
                 << "Admission Type"
                 << "Preadmit Number"
                 << "Prior Patient Location"
                 << "Attending Doctor"
                 << "Referring Doctor"
                 << "Consulting Doctor"
                 << "Hospital Service"
                 << "Temporary Location"
                 << "Preadmit Test Indicator"
                 << "Re-admission Indicator"
                 << "Admit Source"
                 << "Ambulatory Status"
                 << "VIP Indicator"
                 << "Admitting Doctor"
                 << "Patient Type"
                 << "Visit Number"
                 << "Financial Class"
                 << "Charge Price Indicator"
                 << "Courtesy Code"
                 << "Credit Rating"
                 << "Contract Code"
                 << "Contract Effective Date"
                 << "Contract Amount"
                 << "Contract Period"
                 << "Interest Code"
                 << "Transfer to Bad Debt Code"
                 << "Transfer to Bad Debt Date"
                 << "Bad Debt Agency Code"
                 << "Bad Debt Transfer Amount"
                 << "Bad Debt Recovery Amount"
                 << "Delete Account Indicator"
                 << "Delete Account Date"
                 << "Discharge Disposition"
                 << "Discharged to Location"
                 << "Diet Type"
                 << "Servicing Facility"
                 << "Bed Status"
                 << "Account Status"
                 << "Pending Location"
                 << "Prior Temporary Location"
                 << "Admit Date/Time"
                 << "Discharge Date/Time"
                 << "Current Patient Balance"
                 << "Total Charges"
                 << "Total Adjustments"
                 << "Total Payments"
                 << "Alternate Visit ID"
                 << "Visit Indicator"
                 << "Other Healthcare Provider";
}

QString hl7Message::message() const
{
    return m_rawMessage;
}

void hl7Message::setMessage(const QString &pMessage)
{
    m_rawMessage   = pMessage;
}

QString hl7Message::segmentID() const
{
    return m_segmentID;
}

void hl7Message::setSegmentID(const QString &pID)
{
    m_segmentID = pID;
}

hl7Field* hl7Message::fieldSeperator()
{
    return m_fieldSeperator;
}

void hl7Message::setFieldSeperator(hl7Field *pFieldSeperator)
{
    m_fieldSeperator = pFieldSeperator;
}

QVector<hl7Field> hl7Message::fields() const
{
    return m_fields;
}

bool hl7Message::parseMessage()
{
    bool    tFound   = false;
    QString tString;
    QString tParsed;

    if (m_rawMessage == "") return false;

    tString = m_rawMessage.mid(0, 3);
    tParsed = m_rawMessage;
    tParsed.remove(0, 3);

    foreach (QString tLoopSID, m_SIDs)
    {
        if (tString == tLoopSID)
        {
            tFound = true;
            break;
        }
    }

    if (tFound)
    {
        setSegmentID(tString);
    }
    else return false;

    tString = tParsed.mid(0, 1);
    tParsed = tParsed.remove(0, 1);

    m_fields << hl7Field("Field Seperator", tString);
    setFieldSeperator(&m_fields.last());

    if (segmentID() == "MSH")
    {
        tString = tParsed.mid(0, 4);
        tParsed = tParsed.remove(0, 5);

        m_fields << hl7Field("Encoding Characters", tString);

        parseFields(tParsed, m_MSH_fields);
    }
    else if (segmentID() == "EVN")
    {
        parseFields(tParsed, m_EVN_fields);
    }
    else if (segmentID() == "PID")
    {
        parseFields(tParsed, m_PID_fields);
    }
    else if (segmentID() == "OBR")
    {
        parseFields(tParsed, m_OBR_fields);
    }
    else if (segmentID() == "OBX")
    {
        parseFields(tParsed, m_OBX_fields);
    }
    else if (segmentID() == "PV1")
    {
        parseFields(tParsed, m_PV1_fields);
    }

    return true;
}

void hl7Message::parseFields(QString pParsed, QVector<QString> pFields)
{
    m_parsedSplit = pParsed.split(fieldSeperator()->value());
    qDebug() << "split: " << QString::number(m_parsedSplit.length()) << "fields: " << QString::number(pFields.length());
    for (int x = 0; x < m_parsedSplit.length(); x++)
    {
        if (x > m_parsedSplit.length() - 1 || x > pFields.length() - 1) break;

        hl7Field tField = hl7Field(pFields[x], m_parsedSplit[x]);
        m_fields << tField;
    }
}

void hl7Message::parseMessageHeader(QString pParsed)
{
    QString tString = pParsed.mid(0, 4);
    QString tParsed = pParsed.remove(0, 5);

    m_fields << hl7Field("Encoding Characters", tString);

    m_parsedSplit = tParsed.split(fieldSeperator()->value());
    for (int x = 0; x < m_parsedSplit.length(); x++)
    {
        switch (x)
        {
            case 0 :
                m_fields << hl7Field("Sending Application", m_parsedSplit[x]);
                break;
            case 1 :
                m_fields << hl7Field("Sending Facility", m_parsedSplit[x]);
                break;
            case 2 :
                m_fields << hl7Field("Receiving Application", m_parsedSplit[x]);
                break;
            case 3 :
                m_fields << hl7Field("Receiving Facility", m_parsedSplit[x]);
                break;
            case 4 :
                m_fields << hl7Field("Date/Time of Message", m_parsedSplit[x]);
                break;
            case 5 :
                m_fields << hl7Field("Security", m_parsedSplit[x]);
                break;
            case 6 :
                m_fields << hl7Field("Message Type", m_parsedSplit[x]);
                break;
            case 7 :
                m_fields << hl7Field("Message Control Id", m_parsedSplit[x]);
                break;
            case 8 :
                m_fields << hl7Field("Processing Id", m_parsedSplit[x]);
                break;
            case 9 :
                m_fields << hl7Field("Version Id", m_parsedSplit[x]);
                break;
            case 10 :
                m_fields << hl7Field("Sequence Number", m_parsedSplit[x]);
                break;
            case 11 :
                m_fields << hl7Field("Continuation Pointer", m_parsedSplit[x]);
                break;
            case 12 :
                m_fields << hl7Field("Accept Acknowledgement Type", m_parsedSplit[x]);
                break;
            case 13 :
                m_fields << hl7Field("Application Acknowledgement Type", m_parsedSplit[x]);
                break;
            case 14 :
                m_fields << hl7Field("Country Code", m_parsedSplit[x]);
                break;
            case 15 :
                m_fields << hl7Field("Character Set", m_parsedSplit[x]);
                break;
            case 16 :
                m_fields << hl7Field("Principal Language of Message", m_parsedSplit[x]);
                break;
            default :
                m_fields << hl7Field("UNK", m_parsedSplit[x]);
        }
    }
}

void hl7Message::parseEventType(QString pParsed)
{
    // http://www.mexi.be/documents/hl7/ch300055.htm

    m_parsedSplit = pParsed.split(fieldSeperator()->value());
    for (int x = 0; x < m_parsedSplit.length(); x++)
    {
        switch (x)
        {
            case 0 :
                m_fields << hl7Field("Event Type Code", m_parsedSplit[x]);
                break;
            case 1 :
                m_fields << hl7Field("Recorded Date/Time", m_parsedSplit[x]);
                break;
            case 2 :
                m_fields << hl7Field("Date/Time Planned Event", m_parsedSplit[x]);
                break;
            case 3 :
                m_fields << hl7Field("Event Reason Code", m_parsedSplit[x]);
                break;
            case 4 :
                m_fields << hl7Field("Operator ID", m_parsedSplit[x]);
                break;
            case 5 :
                m_fields << hl7Field("Event Occurred", m_parsedSplit[x]);
                break;
           default :
                m_fields << hl7Field("UNK", m_parsedSplit[x]);
        }
    }
}

void hl7Message::parsePatientIdentification(QString pParsed)
{
    m_parsedSplit = pParsed.split(fieldSeperator()->value());
    for (int x = 0; x < m_parsedSplit.length(); x++)
    {
        //if (x == m_parsedSplit.length() - 1 && m_parsedSplit[x] == "") continue;

        switch (x)
        {
            case 0 :
                m_fields << hl7Field("Set ID – Patient ID", m_parsedSplit[x]);
                break;
            case 1 :
                m_fields << hl7Field("Patient ID (External ID)", m_parsedSplit[x]);
                break;
            case 2 :
                m_fields << hl7Field("Patient ID (Internal ID)", m_parsedSplit[x]);
                break;
            case 3 :
                m_fields << hl7Field("Alternate Patient ID – PID", m_parsedSplit[x]);
                break;
            case 4 :
                m_fields << hl7Field("Patient Name", m_parsedSplit[x]);
                break;
            case 5 :
                m_fields << hl7Field("Mother’s Maiden Name", m_parsedSplit[x]);
                break;
            case 6 :
                m_fields << hl7Field("Date/Time of Birth", m_parsedSplit[x]);
                break;
            case 7 :
                m_fields << hl7Field("Sex", m_parsedSplit[x]);
                break;
            case 8 :
                m_fields << hl7Field("Patient Alias", m_parsedSplit[x]);
                break;
            case 9 :
                m_fields << hl7Field("Race", m_parsedSplit[x]);
                break;
            case 10 :
                m_fields << hl7Field("Patient Address", m_parsedSplit[x]);
                break;
            case 11 :
                m_fields << hl7Field("Country Code", m_parsedSplit[x]);
                break;
            case 12 :
                m_fields << hl7Field("Phone Number – Home", m_parsedSplit[x]);
                break;
            case 13 :
                m_fields << hl7Field("Phone Number – Business", m_parsedSplit[x]);
                break;
            case 14 :
                m_fields << hl7Field("Primary Language", m_parsedSplit[x]);
                break;
            case 15 :
                m_fields << hl7Field("Marital Status", m_parsedSplit[x]);
                break;
            case 16 :
                m_fields << hl7Field("Religion", m_parsedSplit[x]);
                break;
            case 17 :
                m_fields << hl7Field("Patient Account Number", m_parsedSplit[x]);
                break;
            case 18 :
                m_fields << hl7Field("SSN Number – Patient", m_parsedSplit[x]);
                break;
            case 19 :
                m_fields << hl7Field("Driver’s License Number - Patient", m_parsedSplit[x]);
                break;
            case 20 :
                m_fields << hl7Field("Mother’s Identifier", m_parsedSplit[x]);
                break;
            case 21 :
                m_fields << hl7Field("Ethnic Group", m_parsedSplit[x]);
                break;
            case 22 :
                m_fields << hl7Field("Birth Place", m_parsedSplit[x]);
                break;
            case 23 :
                m_fields << hl7Field("Multiple Birth Indicator", m_parsedSplit[x]);
                break;
            case 24 :
                m_fields << hl7Field("Birth Order", m_parsedSplit[x]);
                break;
            case 25 :
                m_fields << hl7Field("Citizenship", m_parsedSplit[x]);
                break;
            case 26 :
                m_fields << hl7Field("Veterans Military Status", m_parsedSplit[x]);
                break;
            case 27 :
                m_fields << hl7Field("Nationality", m_parsedSplit[x]);
                break;
            case 28 :
                m_fields << hl7Field("Patient Death Date and Time", m_parsedSplit[x]);
                break;
            case 29 :
                m_fields << hl7Field("Patient Death Indicator", m_parsedSplit[x]);
                break;
            default :
                m_fields << hl7Field("UNK", m_parsedSplit[x]);
        }
    }
}

void hl7Message::parseObservationRequest(QString pParsed)
{
    m_parsedSplit = pParsed.split(fieldSeperator()->value());
    for (int x = 0; x < m_parsedSplit.length(); x++)
    {
        switch (x)
        {
            case 0 :
                m_fields << hl7Field("Set ID", m_parsedSplit[x]);
                break;
            case 1 :
                m_fields << hl7Field("Placer Order Number", m_parsedSplit[x]);
                break;
            case 2 :
                m_fields << hl7Field("Filler Order Number", m_parsedSplit[x]);
                break;
            case 3 :
                m_fields << hl7Field("Universal Service ID", m_parsedSplit[x]);
                break;
            case 4 :
                m_fields << hl7Field("Priority", m_parsedSplit[x]);
                break;
            case 5 :
                m_fields << hl7Field("Requested Date/time", m_parsedSplit[x]);
                break;
            case 6 :
                m_fields << hl7Field("Observation Date/Time", m_parsedSplit[x]);
                break;
            case 7 :
                m_fields << hl7Field("Observation End Date/Time", m_parsedSplit[x]);
                break;
            case 8 :
                m_fields << hl7Field("Collection Volume", m_parsedSplit[x]);
                break;
            case 9 :
                m_fields << hl7Field("Collector Identifier", m_parsedSplit[x]);
                break;
            case 10 :
                m_fields << hl7Field("Specimen Action Code", m_parsedSplit[x]);
                break;
            case 11 :
                m_fields << hl7Field("Danger Code", m_parsedSplit[x]);
                break;
            case 12 :
                m_fields << hl7Field("Relevant Clinical Info.", m_parsedSplit[x]);
                break;
            case 13 :
                m_fields << hl7Field("Specimen Received Date/Time", m_parsedSplit[x]);
                break;
            case 14 :
                m_fields << hl7Field("Specimen Source", m_parsedSplit[x]);
                break;
            case 15 :
                m_fields << hl7Field("Ordering Provider", m_parsedSplit[x]);
                break;
            case 16 :
                m_fields << hl7Field("Order Callback Phone Number", m_parsedSplit[x]);
                break;
            case 17 :
                m_fields << hl7Field("Placer field 1", m_parsedSplit[x]);
                break;
            case 18 :
                m_fields << hl7Field("Placer field 2", m_parsedSplit[x]);
                break;
            case 19 :
                m_fields << hl7Field("Filler Field 1", m_parsedSplit[x]);
                break;
            case 20 :
                m_fields << hl7Field("Filler Field 2", m_parsedSplit[x]);
                break;
            case 21 :
                m_fields << hl7Field("Results Rpt/Status Chng - Date/Time", m_parsedSplit[x]);
                break;
            case 22 :
                m_fields << hl7Field("Charge to Practice", m_parsedSplit[x]);
                break;
            case 23 :
                m_fields << hl7Field("Diagnostic Serv Sect ID", m_parsedSplit[x]);
                break;
            case 24 :
                m_fields << hl7Field("Result Status", m_parsedSplit[x]);
                break;
            case 25 :
                m_fields << hl7Field("Parent Result", m_parsedSplit[x]);
                break;
           default :
                m_fields << hl7Field("UNK", m_parsedSplit[x]);
        }
    }
}
