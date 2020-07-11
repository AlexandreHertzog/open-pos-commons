//
// Created by alex on 6/20/20.
//

#ifndef OPEN_POS_CLIENT_PRODUCT_H
#define OPEN_POS_CLIENT_PRODUCT_H

#include <QObject>
#include <QString>

namespace openpos {
namespace commons {
class Product : public QObject {
    Q_OBJECT

public:
    Product();
    Product(const Product &other);
    Product(Product &&other) noexcept;
    Product &operator=(const Product &other);
    Product &operator=(Product &&other) noexcept;

    const QString &getCode() const;
    void setCode(const QString &string);

    const QString &getName() const;
    void setName(const QString &string);

    double getCost() const;
    void setCost(double d);

    const QString &getDescription() const;
    void setDescription(const QString &string);

    const QString &getImageFileName() const;
    void setImageFileName(const QString &string);

private:
    QString code;
    QString name;
    double cost = 0;
    QString description;
    QString imageFileName;
};
}// namespace commons
}// namespace openpos

Q_DECLARE_METATYPE(openpos::commons::Product);

QDataStream &operator<<(QDataStream &stream, const openpos::commons::Product &p);
QDataStream &operator>>(QDataStream &stream, openpos::commons::Product &p);

#endif//OPEN_POS_CLIENT_PRODUCT_H
