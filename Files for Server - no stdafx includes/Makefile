LOADLIBES= -lm
CXXFLAGS= -std=c++11 -Wall -g

all: mysteryGame;

mysteryGame: mysteryFile.o driveway.o ballroom.o billiards.o cellar.o deck.o dining.o foyer.o garden.o hallway.o kitchen.o library.o secret.o sitting.o smoking.o study.o
	g++ $(CXXFLAGS) -o mysteryGame mysteryFile.o driveway.o ballroom.o billiards.o cellar.o deck.o dining.o foyer.o garden.o hallway.o kitchen.o library.o secret.o sitting.o smoking.o study.o

mysteryFile.o: Mystery_Mansion_Game.cpp
	g++ $(CXXFLAGS) -o mysteryFile.o -c Mystery_Mansion_Game.cpp

driveway.o: DrivewaySource.cpp DrivewayHeader.h
	g++ $(CXXFLAGS) -o driveway.o -c DrivewaySource.cpp
	
ballroom.o: BallroomSource.cpp BallroomHeader.h
	g++ $(CXXFLAGS) -o ballroom.o -c BallroomSource.cpp
	
billiards.o: BilliardsSource.cpp BilliardsHeader.h
	g++ $(CXXFLAGS) -o billiards.o -c BilliardsSource.cpp

cellar.o: CellarSource.cpp CellarHeader.h
	g++ $(CXXFLAGS) -o cellar.o -c CellarSource.cpp
	
deck.o: DeckSource.cpp DeckHeader.h
	g++ $(CXXFLAGS) -o deck.o -c DeckSource.cpp
	
dining.o: DiningSource.cpp DiningHeader.h
	g++ $(CXXFLAGS) -o dining.o -c DiningSource.cpp
	
foyer.o: FoyerSource.cpp FoyerHeader.h
	g++ $(CXXFLAGS) -o foyer.o -c FoyerSource.cpp
	
garden.o: GardenSource.cpp GardenHeader.h
	g++ $(CXXFLAGS) -o garden.o -c GardenSource.cpp
	
hallway.o: HallwaySource.cpp HallwayHeader.h
	g++ $(CXXFLAGS) -o hallway.o -c HallwaySource.cpp
	
kitchen.o: KitchenSource.cpp KitchenHeader.h
	g++ $(CXXFLAGS) -o kitchen.o -c KitchenSource.cpp
	
library.o: LibrarySource.cpp LibraryHeader.h
	g++ $(CXXFLAGS) -o library.o -c LibrarySource.cpp
	
secret.o: SecretSource.cpp SecretHeader.h
	g++ $(CXXFLAGS) -o secret.o -c SecretSource.cpp
	
sitting.o: SittingSource.cpp SittingHeader.h
	g++ $(CXXFLAGS) -o sitting.o -c SittingSource.cpp
	
smoking.o: SmokingSource.cpp SmokingHeader.h
	g++ $(CXXFLAGS) -o smoking.o -c SmokingSource.cpp
	
study.o: StudySource.cpp StudyHeader.h
	g++ $(CXXFLAGS) -o study.o -c StudySource.cpp
	
clean:
	# -f succeeds even if files don't exist
	rm -f mysteryGame mysteryFile.o driveway.o ballroom.o billiards.o cellar.o deck.o dining.o foyer.o garden.o hallway.o kitchen.o library.o secret.o sitting.o smoking.o study.o
