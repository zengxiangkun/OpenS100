#include "stdafx.h"
#include "F_GDAT.h"
#include "ISO8211Fuc.h"
#include "NonPrintableCharacter.h"

F_GDAT::F_GDAT()
{	/*
	* Datum Name
	* A
	* Name of the geodetic datum
	*/
	m_dtnm = L"";
	/*
	* Ellipsoid Name
	* A
	* Name of the ellipsoid
	*/
	m_elnm = L"";
	/*
	* Ellipsoid semi major axis
	* b48
	* Semi major axis of the ellipsoid in metre
	*/
	m_esma = 0;
	/*
	* Ellipsoid second parameter type
	* b11
	* {1} - Semi minor axis in metres
	* {2} - Inverse Flattening
	*/
	m_espt = 1;
	/*
	* Ellipsoid second parameter
	* b48
	* The second defining parameter of the ellipsoid
	*/
	m_espm = 0;
	/*
	* Central Meridian Name
	* A
	* Name of the central meridian
	*/
	m_cmnm = L"";
	/*
	* Central Meridian Greenwich Longitude
	* b48
	* Greenwich longitude of the central meridian in degrees
	*/
	m_cmgl = 0;
}

F_GDAT::F_GDAT(const F_GDAT& other)
{
	m_dtnm = other.m_dtnm;
	m_elnm = other.m_elnm;
	m_esma = other.m_esma;
	m_espt = other.m_espt;
	m_espm = other.m_espm;
	m_cmnm = other.m_cmnm;
	m_cmgl = other.m_cmgl;
}

F_GDAT::~F_GDAT()
{

}

void F_GDAT::ReadField(BYTE *&buf)
{
	buf2charArr(m_dtnm, buf);
	buf2charArr(m_elnm, buf);
	m_esma = buf2double(buf, 8);
	m_espt = buf2uint(buf, 1);
	m_espm = buf2double(buf, 8);
	buf2charArr(m_cmnm, buf);
	m_cmgl = buf2double(buf, 8);
}

int F_GDAT::GetFieldLength()
{
	int len = 0;

	len += m_dtnm.GetLength() + 1;
	len += m_elnm.GetLength() + 1;
	len += 8;
	len += 1;
	len += 8;
	len += m_cmnm.GetLength() + 1;
	len += 8;

	return ++len;
}

F_GDAT* F_GDAT::Clone() const
{
	F_GDAT* f_gdat = new F_GDAT();
	f_gdat->m_dtnm = m_dtnm;
	f_gdat->m_elnm = m_elnm;
	f_gdat->m_esma = m_esma;
	f_gdat->m_espt = m_espt;
	f_gdat->m_espm = m_espm;
	f_gdat->m_cmnm = m_cmnm;
	f_gdat->m_cmgl = m_cmgl;

	return f_gdat;
}
