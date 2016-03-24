#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"

using namespace std;

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

struct StatsData
{
	double minFigure = std::numeric_limits<double>::infinity();
	double maxFigure = -std::numeric_limits<double>::infinity();
	double accFigure = 0;
	unsigned countAcc = 0;
};

void HandleData(StatsData & statsData, const double & index)
{
	if (statsData.minFigure > index)
	{
		statsData.minFigure = index;
	}
	if (statsData.maxFigure < index)
	{
		statsData.maxFigure = index;
	}
	statsData.accFigure += index;
	++statsData.countAcc;
}

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const & data) override
	{
		HandleData(temperature, data.temperature);
		HandleData(humidity, data.humidity);
		HandleData(pressure, data.pressure);

		OutputIndicators();
	}

	void OutputIndicators()
	{
		std::cout << "Max Temp " << temperature.minFigure << std::endl;
		std::cout << "Min Temp " << temperature.maxFigure << std::endl;
		std::cout << "Average Temp " << (temperature.accFigure / temperature.countAcc) << std::endl;
		std::cout << std::endl;
		std::cout << "Max Humidity " << humidity.minFigure << std::endl;
		std::cout << "Min Humidity " << humidity.maxFigure << std::endl;
		std::cout << "Average Humidity " << (humidity.accFigure / humidity.countAcc) << std::endl;
		std::cout << std::endl;
		std::cout << "Max Pressure " << pressure.minFigure << std::endl;
		std::cout << "Min Pressure " << pressure.maxFigure << std::endl;
		std::cout << "Average Pressure " << (pressure.accFigure / pressure.countAcc) << std::endl;
		std::cout << "----------------" << std::endl;
	}
	StatsData temperature;
	StatsData humidity;
	StatsData pressure;

};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		humidity = humidity;
		m_temperature = temp;
		pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double humidity = 0.0;
	double pressure = 760.0;
};
