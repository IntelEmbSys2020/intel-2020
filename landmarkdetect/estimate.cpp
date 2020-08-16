#include "estimate.h"

double fx = 3172.1;
double fy = 3171.8;
double cx = 1497.6;
double cy = 1993.0;

void Estimate(flag_detection_t *td, Eular_t current_att){
    double gama = acos(cos(current_att.pitch) * cos(current_att.roll));
	float delta_l, L, H, X, Y;
	bool direction;
    Point2d Oc;

	if(gama / PI * 180 < 1)
		gama = 0;
    td->Pc.z = sqrt(td->square_area * fx * fy  / (td->img_area * cos(current_att.pitch) * cos(current_att.roll)));
	td->Pc.x = (td->center.x - cx) * td->Pc.z / fx;
	td->Pc.y = (td->center.y - cy) * td->Pc.z / fy;
	Oc.x = cx + fx * tan(current_att.roll);
	Oc.y = cy - fy * tan(current_att.pitch);
	delta_l = sqrt(td->Pc.x*td->Pc.x + td->Pc.y*td->Pc.y) * tan(fabs(gama));
    if( ((Oc.x-cx) * (td->center.x-cx) + (Oc.y-cy) * (td->center.y-cy)) > 0 )
	{
		L = td->Pc.z - delta_l;
		direction = 1;
	}
	else
	{
		L = td->Pc.z + delta_l;
		direction = 0;
	}
	H = L * cos(gama);
	if(direction == 0)
	{
		Y = H * tan( current_att.pitch + atan((td->center.y - cy) /  fy) );
		X = H * tan( current_att.roll - atan((td->center.x - cx) /  fx) );
	}
	else
	{
		Y = H * tan( current_att.pitch + atan((td->center.y - cy) /  fy) );
		X = H * tan( current_att.roll - atan((td->center.x - cx) /  fx) );
	}
 
	td->Pw.x = X;
	td->Pw.y = Y;
	td->Pw.z = H;
}