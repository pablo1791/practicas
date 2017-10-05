

void myFgets(char* buffer, int limite ,FILE* archivo);
int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarString(char* buffer);
int val_validarFloat(char* buffer);
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);
int val_getStringWithPoints(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarDni(char* buffer);
int val_getStringAge(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarEdad(char* buffer);
