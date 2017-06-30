using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Text;
using System.Threading;
using System.Windows;

namespace FinalProject
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string _pi;

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

            using (var con = new SqlConnection(conString))
            {
                var cmd = new SqlCommand("[lydia_doza].[GetGuiSentences]", con);
                var adapter = new SqlDataAdapter(cmd);
                var dataTable = new DataTable("Sentences From Database");
                adapter.Fill(dataTable);
                DataGrid.ItemsSource = dataTable.DefaultView;
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

        private void CalculatePi(int digitsToCalcTo)
        {
            var pi = new StringBuilder("3", digitsToCalcTo + 2);

           
        }

        private void ShowProgress(string pi, int totalDigits, int digitsSoFar)
        {
            Debug.Assert(digitsSoFar)
        }
    }
}
