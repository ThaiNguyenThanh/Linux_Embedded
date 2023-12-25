
LIB_NAME:= math

CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
OBJ_DIR := $(CUR_DIR)/obj
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared


create_obj:
	gcc -c -fPIC $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/math.c -o $(OBJ_DIR)/math.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/version.c -o $(OBJ_DIR)/version.o -I $(INC_DIR)

	
create_shared:
	gcc -shared $(OBJ_DIR)/math.o $(OBJ_DIR)/version.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME).so
install_shared:
	cp -f $(LIB_SHARED_DIR)/lib$(LIB_NAME).so /usr/lib
linking_shared:
	gcc  $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/use-shared-library

all_shared: create_obj create_shared install_shared linking_shared


create_static:
	ar rcs $(LIB_STATIC_DIR)/lib$(LIB_NAME).a $(OBJ_DIR)/math.o $(OBJ_DIR)/version.o
install_static:
	cp -f $(LIB_STATIC_DIR)/lib$(LIB_NAME).a /usr/lib
linking_static:
	gcc  $(OBJ_DIR)/main.o  -L$(LIB_STATIC_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/se-static-library

all_static: create_obj create_static install_static linking_static

clean: 
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(BIN_DIR)/*
	rm -rf $(LIB_SHARED_DIR)/*.so
	rm -rf $(LIB_STATIC_DIR)/*.a