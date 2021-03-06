#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QFileInfo>
#include <QVector>
#include <QTreeWidgetItem>

#include <hl7File.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onSelectButtonClicked(bool);

private:
    Ui::MainWindow *ui;

    QVector<hl7File> m_files;

    QTreeWidgetItem* addTreeWidgetItemChild(QTreeWidgetItem *pParent, QString pText);
};

#endif // MAINWINDOW_H

/*
SEQ	LEN	DT      OPT	RP/#	ELEMENT NAME
1	1	ST      R	 	Field Separator
2	4	ST      R	 	Encoding Characters
3	180	HD      O	 	Sending Application
4	180	HD      O	 	Sending Facility
5	180	HD      O	 	Receiving Application
6	180	HD      O	 	Receiving Facility
7	26	TS      O	 	Date/Time of Message
8	40	ST      O	 	Security
9	7	CM_MSG	R	 	Message Type
10	20	ST      R	 	Message Control Id
11	3	PT      R	 	Processing Id
12	8	ID      R	 	Version Id
13	15	NM      O	 	Sequence Number
14	180	ST      O	 	Continuation Pointer
15	2	ID      O	 	Accept Acknowledgement Type
16	2	ID      O	 	Application Acknowledgement Type
17	2	ID      O	 	Country Code
18	6	ID      O	 	Character Set
19	3	CE      O	 	Principal Language of Message
*/
