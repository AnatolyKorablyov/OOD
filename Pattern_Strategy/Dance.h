#pragma once
using namespace std;

struct IDanceBehavior
{
	virtual ~IDanceBehavior() {};
	virtual void Dance() = 0;
};

class WaltzDanceBehavior : public IDanceBehavior
{
public:
	void Dance() override
	{
		cout << "I'm dancing waltz!!!" << endl;
	}
};

class MinuetDanceBehavior : public IDanceBehavior
{
public:
	void Dance() override
	{
		cout << "I'm dancing minuet!!!" << endl;
	}
};

class NoDanceBehavior : public IDanceBehavior
{
public:
	void Dance() override
	{

	}
};