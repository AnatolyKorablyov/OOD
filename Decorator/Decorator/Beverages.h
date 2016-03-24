#pragma once

#include "IBeverage.h"
#include <map>

using namespace std;

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// размер порции
enum  class SizeBeverage
{
	Standart, // стандартная
	Double // двойная 
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description) 
	{}

	double GetCost() const override 
	{
		return 60; 
	}
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino(SizeBeverage drinkSize)
		:CCoffee(drinkSize == SizeBeverage::Standart ? "Capuccino" : "DoubleCapuccino"),
		m_drinkSize(drinkSize)
	{}

	double GetCost() const override 
	{
		return (m_drinkSize == SizeBeverage::Standart ? 80 : 120);
	}
private:
	SizeBeverage m_drinkSize;
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(SizeBeverage drinkSize)
		:CCoffee(drinkSize == SizeBeverage::Standart ? "Latte" : "DoubleLatte"),
		m_drinkSize(drinkSize)
	{}

	double GetCost() const override 
	{
		return (m_drinkSize == SizeBeverage::Standart ? 90 : 130);
	}
private:
	SizeBeverage m_drinkSize;
};

// Тип чая
enum class TeaType
{
	BlackTea,	// черный
	RedTea,		// красный
	GreenTea, // зеленый
	WhiteTea, // белый
};

const map<TeaType, string> VARIETY_OF_TEA = {
	{ TeaType::BlackTea, "BlackTea"},
	{ TeaType::RedTea, "RedTea"},
	{ TeaType::GreenTea, "GreenTea"},
	{ TeaType::WhiteTea, "WhiteTea"}
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(TeaType teaType)
		:CBeverage(VARIETY_OF_TEA.find(teaType)->second)
	{}

	double GetCost() const override 
	{
		return 30; 
	}
};

// Размер порции
enum class ServingSize
{
	Little, // маленькая
	Medium, // средняя
	Big, // большая
};

const map<ServingSize, string> SERVING_SIZE = {
	{ ServingSize::Little, "Little" },
	{ ServingSize::Medium, "Medium" },
	{ ServingSize::Big, "Big" }
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(ServingSize servingSize)
		:CBeverage(SERVING_SIZE.find(servingSize)->second + " Milkshake"),
		m_servingSize(servingSize)
	{}

	double GetCost() const override 
	{ 
		switch (m_servingSize)
		{
		case ServingSize::Big: return 80;
		case ServingSize::Medium: return 60;
		case ServingSize::Little: return 50;
		}
	}
private:
	ServingSize m_servingSize;
};
