CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic

SRC := main.cpp \
       PatientAdmissionClerk.cpp \
       MedicalSupplyManager.cpp \
       EmergencyDepartmentOfficer.cpp \
       AmbulanceDispatcher.cpp

OBJ := $(SRC:.cpp=.o)
BIN := hospital

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
