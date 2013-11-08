#ifndef FORTOTHREAD_H
#define FORTOTHREAD_H

template <class TypeStruct, class FuntionObject, class NumberThread, class Distributor>
class ForToThread
{
    public:
        ForToThread <TypeStruct, FuntionObject,NumberThread>(TypeStruct* Struct,int Init1, int End1)
        {	/*
        	MInit = Init1;
        	MEnd = End1;           	
			Iniciaremos el inicio del proceso y el punto en donde termina, ademas
			inciaremos el contador de elemento que recibira cada thread (MLength).
			Iniciamos la variable de NumberOfThread.
			Seguido de eso haremos el proceso del for llamano a la funcion Do()
        	*/
        }
        virtual ~ForToThread <TypeStruct, FuntionObject, NumberThread>()
        {	/*
			Eliminaremos cualquier cosa que haya sido creado con new
        	*/
        }

    protected:

    private:

    	int MLength;
    	TypeStruct* MPointerStruc;
    	static FuntionObject MFO;
    	static int MInit;
    	static int MEnd;
    	static int MNumberOfThread;

        void Do(FuntionObject FO1 = MFO, int Init1 = MInit, int End1 = MEnd)
        {	

        }

};
#endif // FORTOTHREAD_H
