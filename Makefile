//ghia48.serhan@gmail.com
CXX = D:/Qt/Tools/mingw1120_64/bin/g++.exe
CXXFLAGS = -std=c++17 -Wall -O2
QT_INCLUDE_PATH = D:/Qt/6.7.2/mingw_64/include
QT_LIB_PATH = D:/Qt/6.7.2/mingw_64/lib
MOC = D:/Qt/6.7.2/mingw_64/bin/moc.exe

# Update these paths according to your Qt installation
INCLUDE = -I$(QT_INCLUDE_PATH) -I$(QT_INCLUDE_PATH)/QtWidgets -I$(QT_INCLUDE_PATH)/QtGui -I$(QT_INCLUDE_PATH)/QtCore
LIBS = -L$(QT_LIB_PATH) -lQt6Widgets -lQt6Core -lQt6Gui

SOURCES = main.cpp mainwindow.cpp tree.cpp TreeWidget.cpp
HEADERS = TreeWidget.h MainWindow.h
MOC_SOURCES = $(HEADERS:.h=.moc.cpp)
MOC_OBJECTS = $(MOC_SOURCES:.cpp=.o)
OBJECTS = $(SOURCES:.cpp=.o)
TEST_SOURCES = test.cpp mainwindow.cpp tree.cpp TreeWidget.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
EXECUTABLE = tree.exe
TEST = test.exe

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(OBJECTS) $(MOC_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(TEST): $(TEST_OBJECTS) $(MOC_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

%.moc.cpp: %.h
	$(MOC) $< -o $@

clean:
	del /Q $(OBJECTS) $(EXECUTABLE) $(MOC_SOURCES) $(MOC_OBJECTS) $(TEST) $(TEST_OBJECTS)
