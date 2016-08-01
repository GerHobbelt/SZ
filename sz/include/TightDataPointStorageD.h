/**
 *  @file TightDataPointStorageD.h
 *  @author Sheng Di
 *  @date April, 2016
 *  @brief Header file for the tight data point storage (TDPS).
 *  (C) 2016 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef _TightDataPointStorageD_H
#define _TightDataPointStorageD_H

typedef struct TightDataPointStorageD
{
	int dataSeriesLength;
	int allSameData;
	int exactDataNum;
	double reservedValue;
	
	char* rtypeArray;
	int rtypeArray_size;
	
	char* typeArray; //its size is dataSeriesLength/4 (or xxx/4+1) 
	int typeArray_size;
	
	char* leadNumArray; //its size is exactDataNum/4 (or exactDataNum/4+1)
	int leadNumArray_size;
	
	char* exactMidBytes;
	int exactMidBytes_size;
	
	char* escBytes;
	int escBytes_size;
	
	char* residualMidBits;
	int residualMidBits_size;

} TightDataPointStorageD;

void new_TightDataPointStorageD_fromFlatBytes(TightDataPointStorageD **this, char* flatBytes, int flatBytesLength);
void decompressDataSeries_double(double** data, int dataSeriesLength, TightDataPointStorageD* tdps);
void getSnapshotData_double(double** data, int dataSeriesLength, TightDataPointStorageD* tdps);
void new_TightDataPointStorageD(TightDataPointStorageD **this, int dataSeriesLength, int exactDataNum, 
		char* type, char* exactMidBytes, int exactMidBytes_size,
		char* leadNumIntArray,  //leadNumIntArray contains readable numbers....
		char* resiMidBits, int resiMidBits_size,
		char* escBytes, int escBytes_size,
		char* resiBitLength, int resiBitLengthSize);
void convertTDPStoFlatBytes_double(TightDataPointStorageD *tdps, char** bytes, int *size);
void free_TightDataPointStorageD(TightDataPointStorageD *tdps);

#endif /* ----- #ifndef _TightDataPointStorageD_H  ----- */