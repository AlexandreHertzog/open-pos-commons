//
// Created by alex on 6/20/20.
//

#include "Product.h"

openpos::commons::Product::Product() = default;

openpos::commons::Product::Product(const openpos::commons::Product &other) {
    this->code = other.code;
    this->name = other.name;
    this->cost = other.cost;
    this->description = other.description;
    this->imageFileName = other.imageFileName;
}

openpos::commons::Product::Product(Product &&other) noexcept {
    this->code.swap(other.code);
    this->name.swap(other.name);
    this->cost = other.cost;
    this->description.swap(other.description);
    this->imageFileName.swap(other.imageFileName);
}

openpos::commons::Product &openpos::commons::Product::operator=(const openpos::commons::Product &other) {
    this->code = other.code;
    this->name = other.name;
    this->cost = other.cost;
    this->description = other.description;
    this->imageFileName = other.imageFileName;
    return *this;
}

openpos::commons::Product &openpos::commons::Product::operator=(openpos::commons::Product &&other) noexcept {
    this->code.swap(other.code);
    this->name.swap(other.name);
    this->cost = other.cost;
    this->description.swap(other.description);
    this->imageFileName.swap(other.imageFileName);
    return *this;
}

const QString &openpos::commons::Product::getCode() const {
    return code;
}

void openpos::commons::Product::setCode(const QString &string) {
    this->code = string;
}

const QString &openpos::commons::Product::getName() const {
    return name;
}

void openpos::commons::Product::setName(const QString &string) {
    this->name = string;
}

double openpos::commons::Product::getCost() const {
    return cost;
}

void openpos::commons::Product::setCost(double d) {
    this->cost = d;
}

const QString &openpos::commons::Product::getDescription() const {
    return description;
}

void openpos::commons::Product::setDescription(const QString &string) {
    this->description = string;
}

const QString &openpos::commons::Product::getImageFileName() const {
    return imageFileName;
}

void openpos::commons::Product::setImageFileName(const QString &string) {
    this->imageFileName = string;
}

QDataStream &operator<<(QDataStream &stream, const openpos::commons::Product &p) {
    stream << p.getCode();
    stream << p.getName();
    stream << QString::number(p.getCost());
    stream << p.getDescription();
    stream << p.getImageFileName();
    return stream;
}

QDataStream &operator>>(QDataStream &stream, openpos::commons::Product &p) {
    QString code;
    QString name;
    QString cost;
    QString description;
    QString imageFileName;
    stream >> code;
    stream >> name;
    stream >> cost;
    stream >> description;
    stream >> imageFileName;
    p.setCode(code);
    p.setName(name);
    p.setCost(cost.toDouble());
    p.setDescription(description);
    p.setImageFileName(imageFileName);
    return stream;
}