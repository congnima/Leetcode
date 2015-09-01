//Rectangle Area
//
//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner 
//and top right corner as shown in the figure.
//
//Rectangle Area
//Assume that the total area is never beyond the maximum possible value of int.


class Solution
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		//if (!(A < C && B < D && E < G && F < H))// if it's not rectangle
		//	return 0;

		if (A <= E && E < C && B < H && H <= D)//two rectangle intersect
		{
			if (A == E && B == F && C == G && D == H)
				return (C - A)*(D - B);
			else if (F > B && G < C) // one is subset of the other
				return (C - A)*(D - B) - (H - F)*(G - E);
			else
				return (C - A)*(D - B) + (G - E)*(H - F) - (G - E)*(H - B);
		}	
		else
			return (C - A)*(D - B) + (G - E)*(H - F);
	}
};