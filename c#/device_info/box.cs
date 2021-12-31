//badger
using System;
using System.Drawing;
using System.Media;
using System.Runtime.InteropServices;
using System.Windows.Forms;

public class box:Form
{
	private const int shadow = 0x20000;
	private bool ok;
	private void key_down(object sender, KeyEventArgs e)
	{
		switch (e.KeyCode)
		{
			case Keys.Right: AcceptButton = buttonCancel; CancelButton = buttonOk; break;
			case Keys.Left: AcceptButton = buttonOk; CancelButton = buttonCancel; break;
			default: break;
		}
	}
	private void init()
	{
		Enabled = true;
		ShowInTaskbar = false;
		MinimizeBox = false;
		MaximizeBox = false;
		FormBorderStyle = FormBorderStyle.FixedDialog;
		StartPosition = FormStartPosition.CenterScreen;
		KeyDown += new KeyEventHandler(key_down);
	}
	private void win_setup()
	{
		Text = title;
		Icon = new Icon(icon, icon_size);
		ClientSize = size;
	}
	private void button_setup()
	{
		if (t != type.confirm) { buttonOk.Text = "&Ok"; buttonCancel.Text = "&Cancel"; }
		else { buttonOk.Text = "&Yes"; buttonCancel.Text = "&No"; }
		buttonOk.DialogResult = DialogResult.OK;
		buttonCancel.DialogResult = DialogResult.Cancel;
		AcceptButton = buttonOk;
		CancelButton = buttonCancel;
	}
	private void object_setup()
	{
		if (t == type.message || t == type.confirm) { set(text, new vector2(10, 10), 1); }
		else { set(text, new vector2(10, 10), 2); }
		if (t == type.input) { set(input_box, new vector2(10, Height / 3), 1); }
		set(buttonOk, new vector4(Width - 180, Height / 2, 50, 30));
		set(buttonCancel, new vector4(Width - 130, Height / 2, 80, 30));
		//if (move == false) { SetBounds(Location.X, Location.X, Size.Width, Size.Height); }
	}
	private void anchor_setup()
	{
		text.Anchor = AnchorStyles.Left | AnchorStyles.Right | AnchorStyles.Top;
		if (t==type.input) { input_box.Anchor = AnchorStyles.Left | AnchorStyles.Right | AnchorStyles.Bottom; }
		buttonOk.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
		buttonCancel.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
	}
	private void set(Control c, vector4 v) { c.Location = new Point(v.x, v.y); c.Size = new Size(v.w, v.h); }
	private void set(Control c, vector2 v3, int a1) { c.SetBounds(v3.x, v3.y, Width - 50, Height / (a1 * 3)); }
	private void build()
	{
		win_setup();
		button_setup();
		anchor_setup();
		object_setup();

		Controls.AddRange(new Control[] { text, buttonOk, buttonCancel });
		if (t == type.input) { Controls.Add(input_box); }

		ok = ShowDialog() == DialogResult.OK;
		if (ok == false) { Dispose(); }
	}
	private void setup(string title1, text_box text1,Size? s)
	{
		title = title1; text = text1; size = s ?? new Size(400, 250);
	}

	protected override CreateParams CreateParams { get { CreateParams cp = base.CreateParams; cp.ClassStyle |= shadow; return cp; } }

	public box(string title1, string text1, Size? size1) { init(); setup(title1, new text_box(text1, new style2(null, null, null)),size1); }
	public box(string title1, text_box text1, Size? size1) { init(); setup(title1, text1, size1); }
	public box(string title1, string text1) { init(); setup(title1, new text_box(text1, new style2(null, null, null)), new Size(400,250)); }
	public box(string title1, text_box text1) { init(); setup(title1, text1, new Size(400,250)); }
	public enum type { message, confirm, input };
	public struct style2
	{
		public BorderStyle border;
		public style s;
		public style2(BorderStyle? bs, Color? bc, Color? fc) { border = bs ?? BorderStyle.None; s = new style(bc, fc); }
	};
	public struct style
	{
		public Color back_color;
		public Color fore_color;
		public style(Color? bc, Color? fc) { back_color = bc ?? DefaultBackColor; fore_color = fc ?? Color.Black; }
	};
	public class item : Control
	{
		private void init()
		{
			TabIndex = 8;
		}

		public item(string text, style s, vector4 v4)
		{
			init();
			Text = text.Replace("\n", "\r\n");
			BackColor = s.back_color;
			ForeColor = s.fore_color;
			Location = new Point(v4.x, v4.y);
			Size = new Size(v4.w, v4.y);
		}
	};
	public class text_box : TextBox
	{
		[DllImport("user32.dll")] private static extern bool HideCaret(IntPtr hwnd);
		private void init()
		{
			ReadOnly = true;
			Multiline = true;
			WordWrap = true;
			ScrollBars = ScrollBars.Both;
			AcceptsTab = true;
			TabIndex = 8;
			GotFocus += (a1, a2) => { HideCaret(Handle); };
			Cursor = Cursors.Arrow;
		}

		public text_box(string text, style2 s)
		{
			init();
			Text = text.Replace("\n", "\r\n");
			BorderStyle = s.border;
			BackColor = s.s.back_color;
			ForeColor = s.s.fore_color;
			Select(0, 0);
		}
	};
	public Button buttonOk = new Button();
	public Button buttonCancel = new Button();
	public Icon icon;
	public Size size;
	public Size icon_size = new Size(50, 50);
	public type t { get; private set; }
	public string title;
	public bool move;
	public text_box text;
	public TextBox input_box;
	public void message() { t = type.message; icon = SystemIcons.Information; build(); }
	public void error() { t = type.message; audio.play(SystemSounds.Exclamation); icon = SystemIcons.Error; build(); }
	public void important() { t = type.message; icon = SystemIcons.Exclamation; build(); }
	public void task() { t = type.message; icon = SystemIcons.Asterisk; build(); }
	public bool confirm() { t = type.confirm; icon = SystemIcons.Question; build(); return ok; }
	public string input() { t = type.input; icon = SystemIcons.Application; input_box = new TextBox(); build(); return input_box.Text; }
};