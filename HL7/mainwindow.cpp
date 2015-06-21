#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->selectButton, SIGNAL(clicked(bool)), this, SLOT(onSelectButtonClicked(bool)));

    ui->messageTree->setColumnCount(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSelectButtonClicked(bool)
{
    int                 tCount = 0;
    QDir                tDir;
    //QString             tString = QFileDialog::getExistingDirectory(this, "Select Folder", "C:\"", QFileDialog::ShowDirsOnly);
    QString tString = "D:\\google drive\\HL7\\HL7 Manipulation\\messages";

    ui->pathText->setText(tString);
    ui->messageTree->clear();

    tDir = QDir(tString);
    tDir.setNameFilters(QStringList("*.msg"));

    if (tDir.exists())
    {
        QList<QTreeWidgetItem*> tMessages;
        foreach (QFileInfo tLoopInfo, tDir.entryInfoList())
        {
            m_files << hl7File(tLoopInfo);
            hl7File tFile = m_files.last();

            QTreeWidgetItem *tItem = new QTreeWidgetItem(ui->messageTree);
            tItem->setText(0, tFile.fileInfo().fileName() + " (" + QString::number(tFile.messages().length()) + ")");

            QString tSeperators = "";
            foreach (QString tLoopSep, tFile.seperators())
                tSeperators += tLoopSep + " ";

            tItem->setText(1, tSeperators);

            for (int x = 0; x < tFile.messages().length(); x++)
            {
                hl7Message tMessage = tFile.messages()[x];

                QTreeWidgetItem *tItem1 = new QTreeWidgetItem();
                tItem1->setText(0, tMessage.segmentID() + "(" + QString::number(tMessage.fields().length()) + ")");
                tItem1->setText(1, tMessage.message());
                tItem->addChild(tItem1);


                for (int y = 0; y < tMessage.fields().length(); y++)
                {
                    hl7Field tField = tMessage.fields()[y];

                    QTreeWidgetItem *tItem2 = new QTreeWidgetItem();
                    tItem2->setText(0, tField.value());
                    tItem2->setText(1, tField.name());
                    tItem1->addChild(tItem2);
                }
            }

            tMessages.append(tItem);
            tCount++;
        }

        ui->messageTree->insertTopLevelItems(0, tMessages);
        //ui->messageTree->expandAll();
    }
}

QTreeWidgetItem* MainWindow::addTreeWidgetItemChild(QTreeWidgetItem *pParent, QString pText)
{
    QTreeWidgetItem *tChild = NULL;

    tChild = new QTreeWidgetItem();
    tChild->setText(0, pText);

    pParent->addChild(tChild);

    return tChild;
}
