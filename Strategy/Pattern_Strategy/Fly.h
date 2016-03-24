#pragma once
using namespace std;

struct IFlyBehavior
{
	virtual ~IFlyBehavior() {};
	virtual void Fly() = 0;
protected:
	int m_departuresCount = 0;
};
class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		m_departuresCount += 1;
		cout << "I'm flying with wings!!" << endl;
		cout << "This is my " << m_departuresCount << " departure(s)" << endl;
	}
};

class FlyNoWay : public IFlyBehavior
{
public:
	void Fly() override {}
};
