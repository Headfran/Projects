import java.awt.FlowLayout;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;

public class Fractal extends JFrame
{
    private FractalJPanel zonaDibujo; // JPanel donde se dibuja el fractal
    private JButton aumentaNivelJButton, bajarNivelJButton;
    private JLabel textoNivel;
    private JPanel grupoBotones;    // JPanel donde se muestran los botones

    public Fractal()
    {
        super( "Curva de Koch" );

        // crea el botón con el que se aumentará el nivel
        aumentaNivelJButton = new JButton( "Subir Nivel" );
        aumentaNivelJButton.addActionListener(
            // clase interna anónima
            new ActionListener()
            {
                public void actionPerformed( ActionEvent event )
                {
                    int nivelActual = zonaDibujo.obtenerNivel();
                    nivelActual++;

                    zonaDibujo.establecerNivel( nivelActual );
                    textoNivel.setText( "Nivel: " + nivelActual );
                    repaint();
                }
            }
        );

        // crea el botón con el que se bajará el nivel
        bajarNivelJButton = new JButton( "Bajar Nivel" );
        bajarNivelJButton.addActionListener(
            // clase interna anónima
            new ActionListener()
            {
                public void actionPerformed( ActionEvent event )
                {
                    int nivelActual = zonaDibujo.obtenerNivel();
                    nivelActual--;

                    if ( nivelActual >= zonaDibujo.MIN_RANGE && nivelActual <= zonaDibujo.MAX_RANGE ) {
                        zonaDibujo.establecerNivel( nivelActual );
                        
                        textoNivel.setText( "Nivel: " + nivelActual );
                        repaint();
                    } // fin de if
                }
            }
        );

        // crea una etiqueta donde muestra el nivel de la curva
        textoNivel = new JLabel( "Nivel: 1" );

        // crea el grupo donde guardará los botones
        grupoBotones = new JPanel();
        grupoBotones.setLayout( new FlowLayout() );
        grupoBotones.add( aumentaNivelJButton );
        grupoBotones.add( bajarNivelJButton );
        grupoBotones.add( textoNivel );

        add( grupoBotones, BorderLayout.NORTH );

        zonaDibujo = new FractalJPanel();
        add( zonaDibujo, BorderLayout.CENTER );
    }

    public static void main( String args[] )
    {
        Fractal aplicacion = new Fractal();
        aplicacion.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        aplicacion.setSize( 400, 400 );
        aplicacion.setVisible( true );
    }
}
