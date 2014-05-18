#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#ifndef	TAMANIO_CHAR
#define TAMANIO_CHAR 1
#endif

#ifndef	TAMANIO_REGISTRO
#define TAMANIO_REGISTRO 8
#endif

#ifndef	TAMANIO_UINT
#define TAMANIO_UINT 4
#endif

#ifndef	LONG_MAX_CODIGO_HUFF
#define LONG_MAX_CODIGO_HUFF 32
#endif

#ifndef	SIZE_BUFFER_OUT_BITS
#define SIZE_BUFFER_OUT_BITS 524288
#endif

#ifndef	ORDEN_CONTEXTO
#define ORDEN_CONTEXTO 3
#endif

#ifndef CANTIDAD_CARACTERES
#define CANTIDAD_CARACTERES 256
#endif

#ifndef	SIZE_BUFFER_OUT_BYTES
#define SIZE_BUFFER_OUT_BYTES 65536
#endif

#ifndef	SIZE_BUFFER_IN_BYTES
#define SIZE_BUFFER_IN_BYTES 65536
#endif

#ifndef	LONG_MAX_MATCH
#define LONG_MAX_MATCH 255
#endif

#ifndef FIN_DE_ARCHIVO
#define FIN_DE_ARCHIVO '/'
#endif

#ifndef READ
#define READ								"r" //apertura para lectura. debe existir previamente
#endif

#ifndef	WRITE
#define WRITE								"w" //crea uno nuevo para escritura. si ya existe se borra
#endif

#ifndef	APPEND
#define APPEND								"a" //apertura para agregado al final del archivo. si no existe se crea
#endif

#ifndef	READ_WRITE
#define READ_WRITE							"rw" // combinacion de modos r y w
#endif

#ifndef	LECTURA_ESCRITURA_EXISTENTE
#define LECTURA_ESCRITURA_EXISTENTE			"r+" //apertura para lectura y escritura. con el archivo previamente existente
#endif

#ifndef	LECTURA_ESCRITURA_NO_EXISTENTE
#define LECTURA_ESCRITURA_NO_EXISTENTE		"w+" //apertura para lectura y escritura. si no existe se crea y si existe se borra lo anterior
#endif

#ifndef	LECTURA_Y_APPEND
#define LECTURA_Y_APPEND					"a+" //todo append se hace al final, protegiendo los datos previamente escritos. los read desde el seek. si no existe se crea
#endif

#ifndef	MODO_BINARIO
#define MODO_BINARIO						"b" //modo binario
#endif

#ifndef	LECTOESCRITURA_EXISTENTE_BINARIO
#define LECTOESCRITURA_EXISTENTE_BINARIO 	"r+b" //combinacion modos r+ y b
#endif

#ifndef LECTOESCRITURA_NO_EXISTENTE_BINARIO
#define LECTOESCRITURA_NO_EXISTENTE_BINARIO "w+b" //combinacion modos w+ y b
#endif

#ifndef	LECTURA_BINARIO
#define LECTURA_BINARIO						"rb"
#endif

#ifndef	ESCRITURA_BINARIO
#define ESCRITURA_BINARIO					"wb"
#endif

#ifndef		FIN_DE_LINEA
# define	FIN_DE_LINEA			'\n'
#endif

#ifndef		RES_OK
# define	RES_OK			0
#endif

#ifndef		RES_NULL
# define	RES_NULL		-1
#endif

#ifndef		RES_ERROR
# define	RES_ERROR		-2
#endif

#ifndef		RES_EOF
# define	RES_EOF			-3
#endif

#ifndef		RES_EXISTE
# define	RES_EXISTE		-4
#endif

#ifndef		RES_NO_EXISTE
# define	RES_NO_EXISTE	-5
#endif

#ifndef		CADENA_NO_EXISTE
#define		CADENA_NO_EXISTE		-6
#endif

#ifndef		EXTENSION_INCORRECTA_A
#define		EXTENSION_INCORRECTA_A	-7
#endif

#ifndef		EXTENSION_INCORRECTA_X
#define		EXTENSION_INCORRECTA_X	-8
#endif

#ifndef		EXTENSION_INCORRECTA_L
#define		EXTENSION_INCORRECTA_L	-9
#endif

#ifndef		LZP_NO_EXISTE
#define		LZP_NO_EXISTE 			-10
#endif

#ifndef		OPERACION_INVALIDA
#define		OPERACION_INVALIDA		-11
#endif

#ifndef		NO_ESTAN_ARCHIVOS
#define		NO_ESTAN_ARCHIVOS		-12
#endif

#ifndef		NO_HAY_ARCHIVOS
#define		NO_HAY_ARCHIVOS			-13
#endif

#ifndef		HELP
#define		HELP					-14
#endif

#define PARM_INGRESADO "Parámetro ingresado: "
#define INGRESAR_PARAM "Debe ingresar el parámetro"
#define COMPRIMIR "Hay que comprimir"
#define DESCOMPRIMIR "Hay que descomprimir"
#define OP_INCORRECTA "Opción incorrecta"

#endif /* CONSTANTES_H_ */
