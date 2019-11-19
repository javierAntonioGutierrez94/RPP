typedef struct{
    int codCliente;
    char apellido[31];
    char nombre[31];
    char sexo;
    char domicilio[51];
    char telefono[21];
    int isEmpty;
}eClientes;

typedef struct{
    int codJuego;
    char descripcion[51];
    float importe;
}eJuegos;

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int codAlquiler;
    int codJuego;
    int codCliente;
    eFecha fecha;
    int isEmpty;
}eAlquileres;


/** \brief Imprime los juegos cargados
*
* \param eJuegos* juego puntero de el array juegos
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void mostrarJuegos(eJuegos* juego, int cantidad);

/** \brief inizializa el vector indicando que todas las posiciones de el mismo estan vacias
*
* \param eClientes* client puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void iniAlquiler(eAlquileres* alquiler, int cantidad);

/** \brief Adhiere en una posicion existente de alquileres los valores recibidos como parametros en la primer posicion que esta vacia
*
* \param eAlquileres* alquiler puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void altaAlquiler(eAlquileres* alquiler,int cantidad);

/** \brief Inizializa el vector indicando que todas las posiciones de el mismo estan vacias
*
* \param eClientes* client puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void inicializar(eClientes* client, int cantidad);

/** \brief adhiere en una posicion existente de clientes los valores recibidos como parametros en la primer posicion que esta vacia
*
* \param eClientes* client puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void alta(eClientes* client, int cantidad);

/** \brief Encuentra un cliente por codigo para poder modificarlo
*
* \param eClientes* client puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void modificar(eClientes* client, int cantidad);

/** \brief Realiza una baja logica
*
* \param eClientes* client puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void baja(eClientes* client, int cantidad);

/** \brief Imprime los empleados cargados
*
* \param eClientes* client puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void listar(eClientes* client, int cantidad);

/** \brief Da el promedio y total de todos los juegos alquilados.
*
* \param eAlquileres* alquiler puntero de el array alquileres
* \param cantidad int longitud de el array alquileres
* \param eJuegos* juego puntero de el array juegos
* \param cantidad2 int longitud de el array juegos
* \return la funcion retorna float promedio
*
*/
float informe7(eAlquileres* alquiler,int cantidad,eJuegos* juego,int cantidad2);

/** \brief Lista La cantidad de juegos cuyo importe no supera el promedio de la funcion informe7
*
* \param float promedio valor flotante de la funcion informe7
* \param eJuegos* juego puntero de el array juegos
* \param cantidad2 int longitud de el array juegos
* \return la funcion retorna void
*
*/
void informe8(float promedio,eJuegos* juego,int cantidad);

/** \brief Lista los clientes que alquilaron un juego deterinado
*
* \param eAlquileres* alquiler puntero de el array alquileres
* \param cantidad int longitud de el array alquileres
* \param eClientes* cliente puntero de el array clientes
* \param cantidad2 int longitud de el array clientes
* \return la funcion retorna void
*
*/
void informe9(eAlquileres* alquiler,int cantidad,eClientes* cliente,int cantidad2);

/** \brief Lista los juegos que fueron alquilados por un cliente determinado
*
* \param eAlquileres* alquiler puntero de el array alquileres
* \param cantidad int longitud de el array alquileres
* \param eJuegos* juego puntero de el array juegos
* \param cantidad2 int longitud de el array juegos
* \return la funcion retorna void
*
*/
void informe10(eAlquileres* alquiler,int cantidad,eJuegos* juego,int cantidad2);

/** \brief Lista el juego/s menos alquilado
*
* \param eAlquileres* alquiler puntero de el array alquileres
* \param cantidad int longitud de el array alquileres
* \param eJuegos* juego puntero de el array juegos
* \param cantidad2 int longitud de el array juegos
* \return la funcion retorna void
*
*/
void informe11(eAlquileres* alquiler,int cantidad,eJuegos* juego,int cantidad2);

/** \brief Lista el/los clientes que realizaron mas alquileres
*
* \param eAlquileres* alquiler puntero de el array alquileres
* \param cantidad int longitud de el array alquileres
* \param eClientes* cliente puntero de el array clientes
* \param cantidad2 int longitud de el array clientes
* \return la funcion retorna void
*
*/
void informe12(eAlquileres* alquiler,int cantidad,eClientes* cliente,int cantidad2);

/** \brief Lista todos los juegos alquilados en una fecha determinada
*
* \param eAlquileres* alquiler puntero de el array alquileres
* \param cantidad int longitud de el array alquileres
* \param eJuegos* juego puntero de el array juegos
* \param cantidad2 int longitud de el array juegos
* \return la funcion retorna void
*
*/
void informe13(eAlquileres* alquiler,int cantidad,eJuegos* juego,int cantidad2);

/** \brief Lista todos los clientes que realizaron al menos un alquiler en una fecha determinada
*
* \param eAlquileres* alquiler puntero de el array alquileres
* \param cantidad int longitud de el array alquileres
* \param eClientes* client puntero de el array clientes
* \param cantidad2 int longitud de el array clientes
* \return la funcion retorna void
*
*/
void informe14(eAlquileres* alquiler,int cantidad,eClientes* client,int cantidad2);

/** \brief Lista todos los juegos ordenados de manera descendente usando el metodo de burbuja mas eficiente
*
* \param eJuegos* juego puntero de el array juegos
* \param cantidad int longitud de el array juegos
* \return la funcion retorna void
*
*/
void informe15(eJuegos* juego,int cantidad);

/** \brief Lista todos los clientes ordendos de manera ascendente utilizando el metodo de insercion
*
* \param eClientes* client puntero de el array clientes
* \param cantidad int longitud de el array
* \return la funcion retorna void
*
*/
void informe16(eClientes* client,int cantidad);
