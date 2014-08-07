#!/bin/bash
##############################################################################
##  wCamera
##	
## Will take an image with the rasp-pi and store it in the 
## given location, with a given prifix name and a timestamp.
## 
## SYNOPSIS
##	wCamera [vid|img] [-p 'name'] [-src 'dest']
##
## PARAMETERS
## 	-p 'name'	Will set a prifix name for the image file.
##
##	-src 'dest'	Set the destination path for the taken image.	
##
##	-help 		Will display the help for the camera script.
##
##############################################################################

CMD_STILL="raspistill -o "
CMD_VID="raspivid -o "
ACTION=""
FILEEND=""
PRIFIX=""
SROUCE=""
LENGTH=""

##############################################################################
#	COLLECT PARAMETERS
##############################################################################

while [ $# -gt 0 ]
do
	

	case "$1" in
        	-help)	
			echo 'Will show how to use the function';
			exit
			;;		
		vid)
			ACTION="vid"	
			FILEEND=".h264"
            		;;
		img)
			ACTION="img"
			FILEEND=".jpg"
			;;
		-p)
			shift
            		if [ "$1" != "" ]; then
				PRIFIX=$1	
			fi
            		;;
       	 	-src)
			shift
            		if [ "$1" != "" ]; then
				SROUCE=$1	
			fi
            		;;
		-len)
			shift
            		if [ "$1" != "" ]; then
				LENGTH=$1	
			fi
            		;;
	esac	
	
   	shift
done

if [ "$ACTION" != "vid" ] && [ "$ACTION" != "img" ]; then
	echo "No action was selected! Please choose 'vid' or 'img'"
	exit
fi

if [ "$ACTION" == "vid" ] && [ "$LENGTH" == "" ]; then
	echo "No length was given"
	exit
fi

##############################################################################
#	CAMERA SCRIPT
##############################################################################

DATE=`date "+%Y-%m-%d"`
NOW_S=`date "+%s"`

if [ "$PRIFIX" != "" ]; then
	IMG_NAME=$PRIFIX"_"
fi

IMG_NAME=$IMG_NAME$NOW_S$FILEEND

if [ "$ACTION" == "img" ]; then
	CMD=$CMD_STILL$IMG_NAME
	$CMD
	exit
fi

if [ "$ACTION" == "vid" ]; then
	CMD=$CMD_VID$IMG_NAME" -t "$LENGTH
	$CMD
	exit
fi

exit

##############################################################################
#	END OF SCRIPT
##############################################################################

