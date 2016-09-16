using System;
using System.Threading;
using System.Windows;
using System.Windows.Media;
using System.Windows.Threading;

namespace FinalProject
{
    /// <summary>
    /// Interaction logic for StartThreadWindow.xaml
    /// </summary>
    public partial class StartThreadWindow : Window
    {
        private TranslateTransform _tt;
        private DispatcherTimer _timer;
        public StartThreadWindow()
        {
            var thisThread = Thread.CurrentThread;
            DataContext = new
            {
                ThreadId = thisThread.ManagedThreadId
            };
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            _tt = new TranslateTransform
            {
                X = 0,
                Y = 0
            };

            _timer = new DispatcherTimer
            {
                IsEnabled = true,
                Interval = new TimeSpan(0, 0, 1)
            };

            _timer.Tick += TimerTick;
            _timer.Start();
        }

        /// <summary>
        /// Increments the transform every second by 20
        /// </summary>
        private void TimerTick(object sender, EventArgs e)
        {
            if ((_tt.Y + StackText.Height + Rainbow.Height) < (Panel.Height - Info.Height - Desc.Height))
            {
                _tt.Y += 20;
            }
            else
            {
                Close();
            }
            Rainbow.RenderTransform = _tt;
        }
    }
}
