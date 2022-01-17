@echo off

cd /D "%~dp0"

IF NOT exist "P:\JM\" (
	echo Creating folder P:\JM\
	mkdir "P:\JM"
)

IF exist "P:\JM\CommunityAntiCheat\" (
	echo Removing existing link P:\JM\CommunityAntiCheat
	rmdir "P:\JM\CommunityAntiCheat\"
)

echo Creating link P:\JM\CommunityAntiCheat
mklink /J "P:\JM\CommunityAntiCheat\" "%cd%\JM\CommunityAntiCheat\"

echo Done