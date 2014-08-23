#!/bin/bash
INPUT_DIR=`pwd`
FILES=`ls -1 $INPUT_DIR | grep \..pp`
ERROR=0
for FILE in $FILES; do
	echo "Checando $FILE"
	CPPLINT_ERRORS=`./cpplint.py --root=$INPUT_DIR $FILE  2>&1 >/dev/null`
	NUM_COUNT=`echo $CPPLINT_ERRORS | grep -E -o "Total errors found: [0-9]+" | grep -E -o "[0-9]+"`
	if [ "$NUM_COUNT" == "0" ]; then
		echo "Nenhum erro de estilo detectado! Parabens!"
	else
		echo "$NUM_COUNT erros de estilo detectados. Conserte-os:"
		echo -e "$CPPLINT_ERRORS"
		ERROR=1
	fi;
	python -c "print '-'*100"
done;
DOXYGEN_PATH=`which doxygen`
if [ ! -z "$DOXYGEN_PATH" ]; then
	OLD=`pwd`
	cd $INPUT_DIR
	DOXYGEN_ERRORS=`echo 'OUTPUT_DIRECTORY = /tmp/' | $DOXYGEN_PATH - 2>&1 | grep -o '.*is not documented' | grep -v 'cpplint.py'`
	cd $OLD
	if [ -z "$DOXYGEN_ERRORS" ]; then
		echo "Parece que o Doxygen aprovou sua documentacao! Parabens!"
	else
		echo "Documentacao nao encontrada no codigo para os seguintes objetos:"
		echo -e "$DOXYGEN_ERRORS"
		echo "Registrando erro..."
		ERROR=1
	fi;
else
	echo "Doxygen nao encontrado. Status da documentacao nao avaliado."
fi;
python -c "print '-'*100"
echo "Compilando projeto.."
echo "Compilando no modo 'Debug' (sem otimizacoes)"
COMPILATION_DEBUG=`make CONF=Debug build 2>&1`
if [ $? == 0 ]; then
	echo "Compilacao no modo Debug bem sucedida! Parabens!"
else
	echo "Compilacao falhou! Veja o relatorio:"
	echo -e "$COMPILATION_DEBUG" | grep "\..pp" | grep -v "g++"
	echo "Registrando erro.."
	ERROR=100
fi;
python -c "print '-'*100"
echo "Compilando no modo 'Release' (com otimizacoes)"
COMPILATION_RELEASE=`make CONF=Release build 2>&1`
if [ $? == 0 ]; then
	echo "Compilacao no modo Release bem sucedida! Parabens!"
else
	echo "Compilacao falhou! Veja o relatorio:"
	echo -e "$COMPILATION_RELEASE" | grep "\..pp" | grep -v "g++"
	echo "Registrando erro.."
	ERROR=1
fi;
python -c "print '-'*100"
echo "Limpando arquivos executaveis.."
make clobber 2>&1 1> /dev/null 
echo "Tudo limpo :D"
python -c "print '-'*100"
if [ $ERROR == 1 ]; then
	echo "Erros detectados! Corrija-os e tente novamente!"
	exit 1
else
	echo "Nenhum erro encontrado. Parabens! :D"
fi