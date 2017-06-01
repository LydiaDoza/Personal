using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Threading;
using System.Windows;

namespace FinalProject
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            FillDataGrid();
        }

        /// <summary>
        /// Fills the grid from data in a database.
        /// </summary>
        private void FillDataGrid()
        {
            var conString = ConfigurationManager.ConnectionStrings["guiConnectionString"].ConnectionString;

            using (SqlConnection con = new SqlConnection(conString))
            {
                var cmd = new SqlCommand("[lydia_doza].[GetGuiSentences]", con);
                var adapter = new SqlDataAdapter(cmd);
                var dataTable = new DataTable("Sentences From Database");
                adapter.Fill(dataTable);
                dataGrid.ItemsSource = dataTable.DefaultView;
            }

        }

        /// <summary>
        /// Button click event that creates a new thread that opens a new StartThreadWindow
        /// </summary>
        private void OnCreateNewWindow(object sender, RoutedEventArgs e)
        {

            var thread = new Thread(() =>
            {

                var tempWindow = new StartThreadWindow();
                tempWindow.Show();


                tempWindow.Closed += (sender2, e2) =>
                tempWindow.Dispatcher.InvokeShutdown();
                System.Windows.Threading.Dispatcher.Run();

            });
            thread.SetApartmentState(ApartmentState.STA);
            thread.Start();

        }
    }
}
