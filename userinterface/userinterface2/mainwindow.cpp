#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableStyring()
{
    ui->groupBox->setEnabled(true);
    ui->lblstatus->setText("");
}

void MainWindow::on_btnFrem_pressed()
{
    ui->lblstatus->setText("Kører fremad");
}

void MainWindow::on_btnFrem_released()
{
    ui->lblstatus->setText("");
}

void MainWindow::on_btnVenstre_pressed()
{
    ui->lblstatus->setText("Drejer til venstre");
}

void MainWindow::on_btnVenstre_released()
{
    ui->lblstatus->setText("");
}

void MainWindow::on_btnHojre_pressed()
{
    ui->lblstatus->setText("Drejer til højre");
}

void MainWindow::on_btnHojre_released()
{
    ui->lblstatus->setText("");
}

void MainWindow::on_btnTilbage_pressed()
{
    ui->lblstatus->setText("Kører bagud");
}

void MainWindow::on_btnTilbage_released()
{
    ui->lblstatus->setText("");
}

void MainWindow::on_btnLoeft_clicked()
{
    ui->lblstatus->setText("Løfter objekt");
    ui->groupBox->setEnabled(false);
    QTimer::singleShot(3000,this, SLOT(enableStyring()));

}

void MainWindow::on_btnSaenk_clicked()
{
    ui->lblstatus->setText("Sænker objekt");
    ui->groupBox->setEnabled(false);
    QTimer::singleShot(3000,this, SLOT(enableStyring()));

}
