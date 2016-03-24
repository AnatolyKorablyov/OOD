#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
#include "Fly.h"
#include "Quack.h"
#include "Dance.h"
#include "Duck.h"

using namespace std;


void DrawDuck(const Duck & duck)
{
	duck.Display();
}

void PlayWithDuck(Duck & duck)
{
	duck.Quack();
	duck.Dance();
	duck.Fly();
	DrawDuck(duck);
}

void FlyBirdFly(Duck & duck)
{
	duck.Fly();
	duck.Fly();
	duck.Fly();
	DrawDuck(duck);
}

void main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);
	RedheadDuck redheadDuck;
	FlyBirdFly(redheadDuck);
	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	DeckoyDuck deckoyDuck;
	PlayWithDuck(deckoyDuck);
	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(make_unique<FlyWithWings>());
	PlayWithDuck(modelDuck);
	system("pause");
}