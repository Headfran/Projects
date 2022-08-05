// Clase panel que dibuja la curva de Koch
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.Color;
import javax.swing.JPanel;

public class FractalJPanel extends JPanel 
{
    public final int MAX_RANGE = 15;
    public final int MIN_RANGE = 1;
    private int nivel; // el nivel actual de la curva
    private Color color; // color con el que se pintará la curva

    // constructor inicializa los elementos de la clase
    public FractalJPanel()
    {
        setBackground( new Color( 66, 45, 185 ) );
        color = Color.WHITE;
        nivel = 1;
    } // fin del constructor

    public void establecerNivel( int n )
    {
        if ( ( n >= MIN_RANGE ) && ( n <= MAX_RANGE ) ) { nivel = n; }
    } // fin del método establecer

    public int obtenerNivel()
    {
        return nivel;
    }

    public void paintComponent( Graphics g )
    {
        super.paintComponent( g );

        g.setColor( color );
        dibujaFractal( g, 50, 300, 350, 300, nivel );
    } // fin del método paintComponent

    // método recursivo que dibuja la curva
    public void dibujaFractal( Graphics g, double xA, double yA,
        double xB, double yB, int nivel )
    {
        Graphics2D g2d = ( Graphics2D ) g;

        // Caso base
        if ( nivel == 1 ) {
            g2d.draw( new Line2D.Double( xA, yA, xB, yB ) );
        } // fin de if
        else { // Paso Recursivo
            // calcula la distancia entre los dos puntos
            double distancia = Math.sqrt( Math.pow( xA - xB, 2 ) + Math.pow( yA - yB, 2 ) );

            // crea los puntos nuevos a unir, separando el segmento en
            // tres partes iguales
            double xC, yC, xD, yD, xE, yE;
            
            xC = xA + ( xB - xA ) / 3.0;
            yC = yA + ( yB - yA ) / 3.0;

            xD = xA + 2.0 * ( xB - xA ) / 3.0;
            yD = yA + 2.0 * ( yB - yA ) / 3.0;

            xE = Math.abs( ( ( yB > yA ) ? xA : -xB ) + ( distancia / 2 ) );
            yE = Math.abs( ( ( yB > yA ) ? yA : -yB ) + distancia / 2 * Math.sqrt( 3 ) / 3 );

            if ( yB < yA ) {
                yE = yB + distancia / 2 * Math.sqrt( 3 ) / 3;
            }

            if ( yB < yA && xA > xB ) {
                xE = xA - distancia / 2;
                yE = yA - distancia / 2 * Math.sqrt( 3 ) / 3;
            }
            else if ( xB < xA ) {
                xE = xB + ( distancia / 2 );
                yE = yB - distancia / 2 * Math.sqrt( 3 ) / 3;
            }

            // llamadas recursivas para pintar
            dibujaFractal( g, xA, yA, xC, yC, nivel - 1 );
            dibujaFractal( g, xC, yC, xE, yE, nivel - 1 );
            dibujaFractal( g, xE, yE, xD, yD, nivel - 1 );
            dibujaFractal( g, xD, yD, xB, yB, nivel - 1 );

        } // fin de else
    } // fin del método dibujarFractal

} // fin de la clase FractalJPanel
