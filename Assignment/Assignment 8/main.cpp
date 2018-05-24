#include <QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");

    db.setConnectOptions();

    db.setDatabaseName("mydsn32"); //must be created through ODBC Data Sources (32-bit) in Administrative Tools in Windows Control Panel

    if (db.open())
    {
        qDebug() << "Opened!";

        QSqlQuery qry;

        //Insert a record into the database
        QString sQuery = "INSERT INTO [dbo].[Backstock] ([ItemNo],[ItemName],[ItemAmt],[ItemPrice]) VALUES(:INo,:IName,:IAmt, :IPrice)";

        qry.prepare(sQuery);

        qry.bindValue(":INo", "31337");
        qry.bindValue(":IName", "Usb Drive");
        qry.bindValue(":IAmt", "17");
        qry.bindValue(":IPrice", "24.99");

        //execute the prepared query, inserting a record. Otherwise, report the error
        if (qry.exec())
        {
            qDebug() << "Record inserted";
        }
        else
        {
            qDebug() << "Error = " << db.lastError().text();
        }

        //execute the query provided as a string argument. Otherwise, report the error
        if (qry.exec("SELECT * FROM [test].[dbo].[Backstock]"))
        {
            while(qry.next())
            {
                qDebug() << qry.value(0).toString() << qry.value(1).toString() << qry.value(2).toString() << qry.value(3).toString();
            }
        }
        else
        {
            qDebug() << "Error = " << db.lastError().text();
        }


        //Update an existing record in the database
        sQuery = "UPDATE [dbo].[Backstock] SET ItemPrice=:IPrice WHERE ItemNo = 71125";

        qry.prepare(sQuery);

        qry.bindValue(":IPrice", "9.99");

        if (qry.exec())
        {
            qDebug() << "Record modified";
        }
        else
        {
            qDebug() << "Error = " << db.lastError().text();
        }

        //execute the query provided as a string argument. Otherwise, report the error
        if (qry.exec("SELECT * FROM [test].[dbo].[Backstock]"))
        {
            while(qry.next())
            {
                qDebug() << qry.value(0).toString() << qry.value(1).toString() << qry.value(2).toString() << qry.value(3).toString();
            }
        }
        else
        {
            qDebug() << "Error = " << db.lastError().text();
        }

        //Delete a record from the database
        sQuery = "DELETE FROM [dbo].[Backstock] WHERE ItemName=:IName";

        qry.prepare(sQuery);

        qry.bindValue(":IName", "Radio");


        if (qry.exec())
        {
            qDebug() << "Record deleted";
        }
        else
        {
            qDebug() << "Error = " << db.lastError().text();
        }

        //execute the query provided as a string argument. Otherwise, report the error
        if (qry.exec("SELECT * FROM [test].[dbo].[Backstock]"))
        {
            while(qry.next())
            {
                qDebug() << qry.value(0).toString() << qry.value(1).toString() << qry.value(2).toString() << qry.value(3).toString();
            }
        }
        else
        {
            qDebug() << "Error = " << db.lastError().text();
        }

        qDebug() << "Closing...";
        db.close();
    }
    else
    {
        qDebug() << "Error = " << db.lastError().text();
    }

    return a.exec();
}
