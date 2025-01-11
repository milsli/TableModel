#include "sourcemodel.h"

SourceModel::SourceModel(QObject *parent)
    : QAbstractTableModel{parent}
    , m_rowsCounter{0}
    , m_headers{ "First", "Second", "Third", "Fourth"}
{
}

QModelIndex SourceModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex SourceModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int SourceModel::rowCount(const QModelIndex &parent) const
{
    return m_rowsCounter;

}

int SourceModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant SourceModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.parent().isValid())
        return {};

    if(index.row() >= m_rowsCounter)
        return {};

    if (role == Qt::EditRole || role == Qt::DisplayRole)
        return m_dane[index.row()][index.column()];

    return QVariant();
}

bool SourceModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid() || index.parent().isValid())
        return false;

    if(index.row() >= m_rowsCounter)
        return false;


    if (role == Qt::EditRole || role == Qt::DisplayRole)
    {
        m_dane[index.row()][index.column()] = value.toString();
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

QVariant SourceModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole && section < columnCount() && section >= 0) {
        return m_headers[section];
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

bool SourceModel::insertRows(int row, int count, const QModelIndex &parent)
{
    m_rowsCounter += count;
    beginInsertRows(parent, row, row + count - 1);
    endInsertRows();
    return true;
}

Qt::ItemFlags SourceModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) ; //| Qt::ItemIsEditable;
}
