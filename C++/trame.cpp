//*********************************************************************************************
//* Programme : Camera date : 4/11/2019
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 02/12/2019
//*
//*Programmeurs : Fontaine Thibaud/Cosman Vincent/ Jouen Matthias
//*classe : BTSSN2
//*--------------------------------------------------------------------------------------------------------
//* BUT :  Ce programme a pour but de piloter une camera a distance
//* en lui faisant prendre différents mouvements voulus
//*Programmes associés : AUCUN
//*********************************************************************************************//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include "trame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	port.Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    port.Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HautClick(TObject *Sender)
{
//trame pour lever la camera
	char texte[9];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x06;
	texte[3] = 0x01;
	texte[4] = 0x03;
	texte[5] = 0x01;
	texte[6] = 0x03;
	texte[7] = 0x01;
	texte[8] = 0xFF;
	port.Write(texte, 9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BasClick(TObject *Sender)
{
//trame pour baisser la camera
	char texte[9];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x06;
	texte[3] = 0x01;
	texte[4] = 0x03;
	texte[5] = 0x01;
	texte[6] = 0x03;
	texte[7] = 0x02;
	texte[8] = 0xFF;
	port.Write(texte, 9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ONClick(TObject *Sender)
{
//trame pour allumer la camera
	char texte[6];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x04;
	texte[3] = 0x00;
	texte[4] = 0x02;
	texte[5] =  0xFF;
	port.Write(texte, 6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OFFClick(TObject *Sender)
{
//trame pour éteindre la camera
	char texte[6];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x04;
	texte[3] = 0x00;
	texte[4] = 0x03;
	texte[5] =  0xFF;
	port.Write(texte, 6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GaucheClick(TObject *Sender)
{
//trame pour bouger la camera à gauche
	char texte[9];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x06;
	texte[3] = 0x01;
	texte[4] = 0x03;
	texte[5] = 0x01;
	texte[6] = 0x01;
	texte[7] = 0x03;
	texte[8] = 0xFF;
	port.Write(texte, 9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DroiteClick(TObject *Sender)
{
//trame pour bouger la camera à droite
	char texte[9];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x06;
	texte[3] = 0x01;
	texte[4] = 0x03;
	texte[5] = 0x01;
	texte[6] = 0x02;
	texte[7] = 0x03;
	texte[8] = 0xFF;
	port.Write(texte, 9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopClick(TObject *Sender)
{
////trame pour arreter le mouvement de la camera
	char texte[9];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x06;
	texte[3] = 0x01;
	texte[4] = 0x03;
	texte[5] = 0x01;
	texte[6] = 0x03;
	texte[7] = 0x03;
	texte[8] = 0xFF;
	port.Write(texte, 9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mode_automatiqueClick(TObject *Sender)
{
//trames pour bouger la camera de gauche à droite
	char home[5];
	home[0] = 0x81;
	home[1] = 0x01;
	home[2] = 0x06;
	home[3] = 0x04;
	home[4] = 0xFF;

	char gauche[9];
	gauche[0] = 0x81;
	gauche[1] = 0x01;
	gauche[2] = 0x06;
	gauche[3] = 0x01;
	gauche[4] = 0x07;
	gauche[5] = 0x05;
	gauche[6] = 0x01;
	gauche[7] = 0x03;
	gauche[8] = 0xFF;

	char droite[9];
	droite[0] = 0x81;
	droite[1] = 0x01;
	droite[2] = 0x06;
	droite[3] = 0x01;
	droite[4] = 0x07;
	droite[5] = 0x05;
	droite[6] = 0x02;
	droite[7] = 0x03;
	droite[8] = 0xFF;

	//port.Write(home, 5);
	for(int i = 0; i<3 ;i++)
	{
		port.Write(gauche, 9);
		Sleep(7500);
		port.Write(droite, 9);
		Sleep(7500);
	}
    Sleep(3000);
	port.Write(home, 5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZoomMoinsClick(TObject *Sender)
{
//trame pour dézoomer
	char texte[6];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x04;
	texte[3] = 0x07;
	texte[4] = 0x03;
	texte[5] = 0xFF;

	port.Write(texte, 6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZoomPlusClick(TObject *Sender)
{
//trame pour zoomer
	char texte[6];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x04;
	texte[3] = 0x07;
	texte[4] = 0x02;
	texte[5] = 0xFF;

	port.Write(texte, 6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZoomStopClick(TObject *Sender)
{
//trame pour stoper le zoom
    char texte[6];
	texte[0] = 0x81;
	texte[1] = 0x01;
	texte[2] = 0x04;
	texte[3] = 0x07;
	texte[4] = 0x00;
	texte[5] = 0xFF;

	port.Write(texte, 6);
}
//---------------------------------------------------------------------------

/*
Fonction permettant de modifier le niveau de zoom selon la position de la Scrollbar
*/

void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
	Position = ScrollBar1->Position;
	Memo1->Lines->Add(Position);

	if (Position == 0)
	{
		char zoommin[9];
		zoommin[0] = 0x81;
		zoommin[1] = 0x01;
		zoommin[2] = 0x04;
		zoommin[3] = 0x47;
		zoommin[4] = 0x00;
		zoommin[5] = 0x00;
		zoommin[6] = 0x00;
		zoommin[7] = 0x00;
		zoommin[8] = 0xFF;

		port.Write(zoommin, 9);
	}

	if ((Position >= 100) && (Position <= 250))
	{
		char zoom1[9];
		zoom1[0] = 0x81;
		zoom1[1] = 0x01;
		zoom1[2] = 0x04;
		zoom1[3] = 0x47;
		zoom1[4] = 0x00;
		zoom1[5] = 0x00;
		zoom1[6] = 0x0A;
		zoom1[7] = 0x0F;
		zoom1[8] = 0xFF;

		port.Write(zoom1, 9);
	}

	if ((Position >= 251) && (Position <= 400))
	{
		char zoom2[9];
		zoom2[0] = 0x81;
		zoom2[1] = 0x01;
		zoom2[2] = 0x04;
		zoom2[3] = 0x47;
		zoom2[4] = 0x00;
		zoom2[5] = 0x01;
		zoom2[6] = 0x04;
		zoom2[7] = 0x05;
		zoom2[8] = 0xFF;

		port.Write(zoom2, 9);
	}

	if ((Position >= 401) && (Position <= 550))
	{
		char zoom3[9];
		zoom3[0] = 0x81;
		zoom3[1] = 0x01;
		zoom3[2] = 0x04;
		zoom3[3] = 0x47;
		zoom3[4] = 0x00;
		zoom3[5] = 0x01;
		zoom3[6] = 0x0D;
		zoom3[7] = 0x0B;
		zoom3[8] = 0xFF;

		port.Write(zoom3, 9);
	}

	if ((Position >= 551) && (Position <= 700))
	{
		char zoom4[9];
		zoom4[0] = 0x81;
		zoom4[1] = 0x01;
		zoom4[2] = 0x04;
		zoom4[3] = 0x47;
		zoom4[4] = 0x00;
		zoom4[5] = 0x02;
		zoom4[6] = 0x07;
		zoom4[7] = 0x01;
		zoom4[8] = 0xFF;

		port.Write(zoom4, 9);
	}

	if ((Position >= 701) && (Position <= 850))
	{
		char zoom5[9];
		zoom5[0] = 0x81;
		zoom5[1] = 0x01;
		zoom5[2] = 0x04;
		zoom5[3] = 0x47;
		zoom5[4] = 0x00;
		zoom5[5] = 0x03;
		zoom5[6] = 0x00;
		zoom5[7] = 0x07;
		zoom5[8] = 0xFF;

		port.Write(zoom5, 9);
	}

	if (Position == 1023)
	{
		char zoommax[9];
		zoommax[0] = 0x81;
		zoommax[1] = 0x01;
		zoommax[2] = 0x04;
		zoommax[3] = 0x47;
		zoommax[4] = 0x00;
		zoommax[5] = 0x03;
		zoommax[6] = 0xFF;
		zoommax[7] = 0xFF;
		zoommax[8] = 0xFF;

		port.Write(zoommax, 9);
	}


}
//---------------------------------------------------------------------------



