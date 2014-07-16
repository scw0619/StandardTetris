// All contents of this file written by Colin Fahey ( http://colinfahey.com )
// 2007 June 4 ; Visit web site to check for any updates to this file.



#ifndef STStrategyUserDefinedHeader
#define STStrategyUserDefinedHeader



#include "CPF.StandardTetris.STBoard.h"
#include "CPF.StandardTetris.STPiece.h"
#include "CPF.StandardTetris.STStrategy.h"



// Disable unimportant "symbol too long" error for debug builds of STL string
#pragma warning( disable : 4786 )

#include <string>
#include <vector>
using namespace std;




namespace CPF
{
	namespace StandardTetris
	{



		class STStrategyUserDefined : public STStrategy
		{

		public: virtual string GetStrategyName ( );


			// WARNING: Moves requiring rotation must wait until piece has fallen by
			// at least one row!
			// Perform all rotations, and then perform translations.  This
			// avoids the problem of getting the piece jammed on the sides
			// of the board where rotation is impossible. ***
			// Also, the following strategy does not take advantage of the
			// possibility of using free-fall and future movements to
			// slide under overhangs and fill them in.

		public: virtual void GetBestMoveOncePerPiece
        (
            STBoard & currentBoard,
            STPiece & currentPiece,
            int nextPieceFlag, // 0 == no next piece available or known
            int nextPieceShape, // 0 == no piece available or known
            int & bestRotationDelta, // 0 or {0,1,2,3}
            int & bestTranslationDelta // 0 or {...,-2,-1,0,1,2,...}
        );



		private: static double PrivateStrategy
					 ( 
					 int                       flagCalledFromParentPly,  // True if called from a parent level
					 STBoard &   ref_CurrentBoard,
					 STPiece &   ref_CopyOfCurrentPiece,
					 int &                     ref_bestRotationDelta,    // 0 or {0,1,2,3} 
					 int &                     ref_bestTranslationDelta  // 0 or {...,-2,-1,0,1,2,...}
					 );

		private: static void PrivateStrategyEvaluate
					 ( 
					 STBoard &  board,
					 STPiece &  piece,
		 			 double & rating
					 );
		};



	}
}



#endif





