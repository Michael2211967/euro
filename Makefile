# Erkennung des Betriebssystems
ifeq ($(OS),Windows_NT)
    # Windows-Einstellungen
    TARGET = euro.exe
    EXT = .exe
    ifdef MSYSTEM
        RM = rm -f
        FIX_PATH = $1
    else
        RM = del /Q
        FIX_PATH = $(subst /,\,$1)
    endif
else
    # Linux/WSL-Einstellungen
    RM = rm -f
    TARGET = euro
    EXT =
    FIX_PATH = $1
endif

CC = gcc
CFLAGS = -Wall -O2 -s -I../mod
MOD_DIR = ../mod
OBJ = euro.o $(MOD_DIR)/upper.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

euro.o: euro.c
	$(CC) $(CFLAGS) -c euro.c

$(MOD_DIR)/upper.o: $(MOD_DIR)/upper.c
	$(CC) $(CFLAGS) -c $(MOD_DIR)/upper.c -o $(MOD_DIR)/upper.o

clean:
	$(RM) $(TARGET) *.o $(call FIX_PATH,$(MOD_DIR)/*.o)