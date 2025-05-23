#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class ConfiguratableSensorStub: public IWeatherSensor {
        public:
        double temp;
        int precip;
        int humid;
        int windspeed; 
        ConfiguratableSensorStub(double temp,int precip,int humid,int windspeed)
        {
            this->temp = temp;
            this->precip = precip;
            this->humid = humid;
            this->windspeed = windspeed;
        }
        int Humidity() const override {
            return humid;
        }

        int Precipitation() const override {
            return precip;
        }

        double TemperatureInC() const override {
            return temp;
        }

        int WindSpeedKMPH() const override {
            return windspeed;
        }
    };
    string Report(const IWeatherSensor& sensor)
    {
        
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
    
    void TestWeatherReportCase(double temp, int precip, int humidity, int wind, const std::string& expectedSubstring)
    {
        ConfiguratableSensorStub sensor(temp, precip, humidity, wind);
        std::string report = Report(sensor);
        std::cout << "Report: " << report << std::endl;
        assert(report.find(expectedSubstring) != std::string::npos);
    }

    void TestHighPrecipitation()
    {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        
        ConfiguratableSensorStub sensor(26, 60, 72, 50); 
        string report = Report(sensor);
        cout << report << endl;
        assert(report.find("rain") != string::npos);
        assert(report.length() > 0);
    }
}

void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestWeatherReportCase(26, 70, 72, 52, std::string("rain"));
    WeatherSpace::TestWeatherReportCase(26, 60, 72, 30, std::string("partly cloudy"));
    WeatherSpace::TestWeatherReportCase(26, 62, 72, 30, std::string("partly cloudy"));
    WeatherSpace::TestWeatherReportCase(26, 60, 72, 50, std::string("rain"));
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}
