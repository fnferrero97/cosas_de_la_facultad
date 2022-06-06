#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);

    foreach(QAbstractButton* boton, this->ui->buttonGroup->buttons()){
        QObject::connect(boton,&QPushButton::clicked,this,&TicTacToe::on_clicked(qobject_cast<QPushButton*>(boton)));
    }

}

TicTacToe::~TicTacToe(){
    delete ui;
}


void* TicTacToe::on_clicked(QPushButton* b1){
    if (b1->text() == ""){
        if( this->player == 0){
            b1->setText("X");
            this->player++;
            b1->setEnabled(false);
        }else{
            b1->setText("O");
            this->player--;
            b1->setEnabled(false);
        }
    }else{
        b1->setEnabled(false);
    }
    this->movidas++;
    this->check();
}


void TicTacToe::on_pushButton_clicked(){
    this->on_clicked(this->ui->pushButton);
}


void TicTacToe::on_pushButton_2_clicked()
{
    this->on_clicked(this->ui->pushButton_2);
}


void TicTacToe::on_pushButton_3_clicked()
{
    this->on_clicked(this->ui->pushButton_3);
}


void TicTacToe::on_pushButton_4_clicked()
{
    this->on_clicked(this->ui->pushButton_4);
}


void TicTacToe::on_pushButton_5_clicked()
{
    this->on_clicked(this->ui->pushButton_5);
}


void TicTacToe::on_pushButton_6_clicked()
{
    this->on_clicked(this->ui->pushButton_6);
}


void TicTacToe::on_pushButton_7_clicked()
{
    this->on_clicked(this->ui->pushButton_7);
}


void TicTacToe::on_pushButton_8_clicked()
{
    this->on_clicked(this->ui->pushButton_8);
}


void TicTacToe::on_pushButton_9_clicked()
{
    this->on_clicked(this->ui->pushButton_9);
}

void TicTacToe::check(){
    if(this->movidas==9){
         this->ui->label->setText("PERDIERON PTS");
            this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    //button1
    if((this->ui->pushButton->text() == "X" && this->ui->pushButton_2->text() == "X" && this->ui->pushButton_3->text() == "X") || (this->ui->pushButton->text() == "O" && this->ui->pushButton_2->text() == "O" && this->ui->pushButton_3->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    if((this->ui->pushButton->text() == "X" && this->ui->pushButton_5->text() == "X" && this->ui->pushButton_9->text() == "X") || (this->ui->pushButton->text() == "O" && this->ui->pushButton_5->text() == "O" && this->ui->pushButton_9->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    if((this->ui->pushButton->text() == "X" && this->ui->pushButton_4->text() == "X" && this->ui->pushButton_7->text() == "X") || (this->ui->pushButton->text() == "O" && this->ui->pushButton_4->text() == "O" && this->ui->pushButton_7->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    //button2
    if((this->ui->pushButton_2->text() == "X" && this->ui->pushButton_5->text() == "X" && this->ui->pushButton_8->text() == "X") || (this->ui->pushButton_2->text() == "O" && this->ui->pushButton_5->text() == "O" && this->ui->pushButton_8->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton_2->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    //button3
    if((this->ui->pushButton_3->text() == "X" && this->ui->pushButton_6->text() == "X" && this->ui->pushButton_9->text() == "X") || (this->ui->pushButton_3->text() == "O" && this->ui->pushButton_6->text() == "O" && this->ui->pushButton_9->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton_3->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    if((this->ui->pushButton_3->text() == "X" && this->ui->pushButton_5->text() == "X" && this->ui->pushButton_7->text() == "X") || (this->ui->pushButton_3->text() == "O" && this->ui->pushButton_5->text() == "O" && this->ui->pushButton_7->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton_3->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    //button4
    if((this->ui->pushButton_4->text() == "X" && this->ui->pushButton_5->text() == "X" && this->ui->pushButton_6->text() == "X") || (this->ui->pushButton_4->text() == "O" && this->ui->pushButton_5->text() == "O" && this->ui->pushButton_6->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton_4->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }

    //button 7
    if((this->ui->pushButton_7->text() == "X" && this->ui->pushButton_8->text() == "X" && this->ui->pushButton_9->text() == "X") || (this->ui->pushButton_7->text() == "O" && this->ui->pushButton_8->text() == "O" && this->ui->pushButton_9->text() == "O")){
        this->ui->label->setText("GANO " + this->ui->pushButton_7->text());
        this->game_over = true;
        this->ui->Jugar->setEnabled(true);
    }
}



void TicTacToe::on_Jugar_clicked()
{

    this->ui->pushButton->setText("");
    this->ui->pushButton->setEnabled(true);

    this->ui->pushButton_2->setText("");
    this->ui->pushButton_2->setEnabled(true);

    this->ui->pushButton_3->setText("");
    this->ui->pushButton_3->setEnabled(true);

    this->ui->pushButton_4->setText("");
    this->ui->pushButton_4->setEnabled(true);

    this->ui->pushButton_5->setText("");
    this->ui->pushButton_5->setEnabled(true);

    this->ui->pushButton_6->setText("");
    this->ui->pushButton_6->setEnabled(true);

    this->ui->pushButton_7->setText("");
    this->ui->pushButton_7->setEnabled(true);

    this->ui->pushButton_8->setText("");
    this->ui->pushButton_8->setEnabled(true);

    this->ui->pushButton_9->setText("");
    this->ui->pushButton_9->setEnabled(true);

    this->movidas = 0;
    this->player = 0;
    this->game_over = false;
    this->ui->Jugar->setEnabled(false);
    this->ui->label->setText("TIC TAC TOE");
}

