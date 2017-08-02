//---------------------------------------------------------------------------

#ifndef MatrixVH
#define MatrixVH
//---------------------------------------------------------------------------
class TVec4
{
	union
	{
		struct
		{
			MBTi fa[4];

		};
		struct
		{
			MBTi fx;
			MBTi fy;
			MBTi fz;
			MBTi fw;
		};
	};
};

class TMatrix : public TMyObject {
private:
	union
	{
		struct
		{
			MBTi fa[4][4];

		};
		struct
		{
			TVec4 fvx;
			TVec4 fvy;
			TVec4 fvz;
			TVec4 fvw;
		};
    };
public:
    void Add(const TMatrix& aMatrix);
    void Multiply(const TMatrix& aMatrix,TMatrix& Dest);
    void Multiply(const TVec4& aSource,TVec4& aDest) const;
    void Multiply(MBTi aValue);
    bool Invert();
    void Transpose();
    void SetIdentity();
};

void TMatrix::Add(const TMatrix& aMatrix)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            fa[i][j] += aMatrix.fa[i][j];
}

void TMatrix::Multiply(const TMatrix& aMultMatrix,TMatrix& Dest)
{
    for (int Row=0;Row<4;Row++)
        for (int Col=0;Col<4;Col++)
        {
            Dest.fa[Row][Col] = 0;
            for (int mRow=0;mRow<4;mRow++)
                for (int mCol=0;mCol<4;mCol++)
                    Dest.fa[Row][Col] += fa[Row][mCol]*aMultMatrix.fa[mRow][Col];
        }
}

void TMatrix::Multiply(MBTi aValue)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            fa[i][j] *= aValue;
}

void TMatrix::Multiply(const TVec4& aSource,TVec4& aDest) const
{
    
}
bool TMatrix::Invert(){};
void TMatrix::Transpose(){};
void TMatrix::SetIdentity(){};


#endif
