


int triangleArea(int ax, int ay, int bx, int by, int cx, int cy){

    return abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by))/2;
}
