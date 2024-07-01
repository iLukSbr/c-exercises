int comprimeSequencia (byte* in, int n, byte* out)
{
    int inicio = 0, usadas = 0, val, cont;
    while (inicio < n)
    {
        cont = 0;
        val = in [inicio];
        while (inicio+cont < n && in [inicio+cont] == val)
            cont++;
        if (cont == 1)
        {
            out [usadas] = val;
            usadas++;
        }
        else
        {
            out [usadas] = cont;
            out [usadas+1] = val;
            usadas += 2;
        }
        inicio += cont;
    }
    return (usadas);
}
