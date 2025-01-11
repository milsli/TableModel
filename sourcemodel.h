#ifndef SOURCEMODEL_H
#define SOURCEMODEL_H

#include <QAbstractTableModel>
#include <QVector2D>

class SourceModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit SourceModel(QObject *parent = nullptr);


    QModelIndex index(int row, int column,
                                          const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QModelIndex parent(const QModelIndex &child) const override;


private:
    int m_rowsCounter;
    QString m_dane[40000][4];
    QVector<QString> m_headers;
};

#endif // SOURCEMODEL_H
