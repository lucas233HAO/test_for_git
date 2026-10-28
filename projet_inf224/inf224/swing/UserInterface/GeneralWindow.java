package UserInterface;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Date;

public class GeneralWindow extends JFrame{
	
	private static final long serialVersionUID = 1L;
	private JTextArea textArea;
	private Client myClient = null;
	private String fileName = "no file name";
	private Boolean sendPlay = false;
	private Boolean sendFind = false;
	
	
	public String getFileName()
	{	
		
		return fileName; 
	}
	
	public Boolean getSendPlay()
	{	
		return sendPlay;
	}

	public Boolean getSendFind()
	{	
		return sendFind;
	}
	
	public void setSendPlay(boolean b)
	{
		sendPlay = b;
	}
	
	public void setSendFind(boolean b)
	{
		sendFind = b;
	}
   	
	public void addTextArea(String t)
	{
		textArea.append(t + "\n");
	}
	
	public void setClient(Client clientTcp)
	{
		this.myClient = clientTcp;
		addTextArea("succes set TCP client in the window \n");
	}
	
    public void createWindow()
    {
		//set a new panel
		JPanel southJPanel = new JPanel();
		
		// set new buttons, new text area and new scrollPane
		JButton addTextButton1 = new JButton("find");
        JButton addTextButton2 = new JButton("play");
        JButton quitButton = new JButton("close");
        textArea = new JTextArea(20, 20);
        
        
        
        //add buttons to the panel, add textArea to the scrollpane
        southJPanel.add(addTextButton1);
        southJPanel.add(addTextButton2);
        southJPanel.add(quitButton);
        JScrollPane scrollPane = new JScrollPane(textArea);
        
  
        // add Jpanel and scrollpane to JFrame
        getContentPane().add(southJPanel, BorderLayout.SOUTH);
        getContentPane().add(scrollPane, BorderLayout.CENTER);
        
        
        // add listener to quit button
        quitButton.addActionListener(new LeaveListener());
        // add listener to text buttons
        addTextButton1.addActionListener(new AddTextButton1Listener());
        addTextButton2.addActionListener(new AddTextButton2Listener());
		
        
        //create a new menu bar
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);
        
        // add menu bar to jFrame
        getContentPane().add(menuBar, BorderLayout.NORTH);
        setJMenuBar(menuBar);

        
        //bind listener to menu items
        JMenuItem text1MenuItem = new JMenuItem("find");
        JMenuItem text2MenuItem = new JMenuItem("play");
        JMenuItem leaveMenuItem = new JMenuItem("quit");
        text1MenuItem.addActionListener(new AddTextButton2Listener());
        text2MenuItem.addActionListener(new AddTextButton1Listener());
        leaveMenuItem.addActionListener(new LeaveListener());
        
        //add menu items to menu
        menu.add(text1MenuItem);
        menu.add(text2MenuItem);
        menu.add(leaveMenuItem);
               
        // create tool bar
        JToolBar toolbar = new JToolBar();
        JButton toolBarButton1 = new JButton("find");
        JButton toolBarButton2 = new JButton("play");
        JButton leaveToolBarButton = new JButton("leave");
        toolBarButton1.addActionListener(new AddTextButton1Listener());
        toolBarButton2.addActionListener(new AddTextButton2Listener());
        leaveToolBarButton.addActionListener(new LeaveListener());
        
        // add buttons to tool bar
        menuBar.add(toolBarButton1);
        menuBar.add(toolBarButton2);
        menuBar.add(leaveToolBarButton);
        
        
        // default settings
         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         pack();
         setVisible(true);

    }
    

    class LeaveListener implements ActionListener {
    	@Override
    	public void actionPerformed(ActionEvent e) {
    		System.exit(0);
    	}
    }

    class AddTextButton1Listener implements ActionListener { //find
    	@Override
    	public void actionPerformed(ActionEvent e) {
    		fileName = getLastCommand();
    		sendFind = true;
    	}
	}
    
    class AddTextButton2Listener implements ActionListener { //play
    	@Override
    	public void actionPerformed(ActionEvent e) {
    	    fileName = getLastCommand(); 
    		sendPlay = true;
        	}
     }
    
    public String getLastCommand() {         
        String text = textArea.getText();
        String[] rows = text.split("\n");
       return rows[rows.length-1];    
    }
}