#ifndef _TYPES_H_
#define _TYPES_H_

/**
 * @brief Industries Repository Graph
 */
namespace toha
{
	enum TipoEtiqueta
	{
		Simple	=	(1 << 3),
		Propia	=	(1 << 4)
	};

	enum Status{
		Ok 		=  1,
		Error 	= -1
	};
};

#endif /*_TYPES_H_*/
