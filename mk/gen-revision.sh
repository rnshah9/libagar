#!/bin/sh
#
# Generate CPP define for a SVN revision number if sources are from SVN
# (and svn is available). Otherwise, define the revision number to be 0.
#

TOP=$1
DEFN=$2
if [ "${TOP}" = "" -o "${DEFN}" = "" ]; then
	echo "Usage: gen-revision.sh [top-dir] [define]"
	exit 1
fi

echo "/* Generated by gen-revision.sh */"
echo "#ifndef $DEFN"

if [ -e "${TOP}/.svn" ]; then
	IFS=":"
	SVN=""
	for path in $PATH; do
		if [ -x "${path}/svn" ]; then
			SVN="${path}/svn"
			break
		elif [ -x "${path}/svn.exe" ]; then
			SVN="${path}/svn.exe"
			break
		fi
	done
	if [ "${SVN}" != "" ]; then
		SVN_REV=`${SVN} info -R --show-item revision |sort -n |tail -n 1 |awk '{print $1}'`
		if [ "$?" = "0" -a "${SVN_REV}" != "" ]; then
			echo "#define $DEFN $SVN_REV"
		else
			echo '/* svn info failed */'
			echo "#define $DEFN 0"
		fi
	else
		echo '/* svn not found */'
		echo "#define $DEFN 0"
	fi
else
	echo '/* not using SVN sources */'
	echo "#define $DEFN 0"
fi
echo '#endif'
