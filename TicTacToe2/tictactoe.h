#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "qpushbutton.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private slots:
    void* on_clicked(QPushButton *);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void check();


    void on_Jugar_clicked();

private:
    Ui::TicTacToe *ui;
    int player = 0;
    int movidas = 0;
    bool game_over = false;
};
#endif // TICTACTOE_H
