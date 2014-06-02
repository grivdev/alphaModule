/*
 *	alpha.c: This is a module created step by step using the basic_module.c file.
 */



/*
 *	Includes
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux.init.h>
#include <linux/fs.h>
//#include <asm/uaccess.h>	/* For put_user */



/*
 *	Defines
 */

#define MODULE_AUTH "Christos Grivas <chgrivas7@gmail.com>"
#define MODULE_DESC "Description"
#define MODULE_LIC  "GPL"
#define SUCCESS 0


/*
 *	funcs' prototypes
 */

//static int __init alpha_init(void);		/* not sure if prototype is necessary */
//static void __exit alpha_exit(void);

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);



/*
 *	global vars and structs
 */

static int Major;	
static int Device_Open = 0;

static struct file_operations fops = {
	.read = device_read,
	.write = device_write,	
	.open = device_open,
	.release = device_release
};


/*
 *	module_init & module_exit funcs
 */

static int __init alpha_init(void)
{
	Major = register_chrdev(0, DEVICE_NAME, &fops);
	
	if (Major < 0) {
	  printk(KERN_ALERT "Registering char device failed with %d\n", Major);
	  return Major;
	}


	//alpha_init body


	return SUCCESS;
}

static void __exit alpha_exit(void);
{
	unregister_chrdev(Major, DEVICE_NAME);

	//alpha_exit body
}



/*
 *	Methods
 */

static int device_open(struct inode *, struct file *)
{

}

static int device_release(struct inode *, struct file *)
{

}

static ssize_t device_read(struct file *, char *, size_t, loff_t *)
{

}

static ssize_t device_write(struct file *, const char *, size_t, loff_t *)
{

}


/*
 *	Macros
 */

module_init(alpha_init);
module_exit(alpha_exit);

MODULE_AUTHOR(MODULE_AUTH);
MODULE_DESCRIPTION(MODULE_DESC);
MODULE_LICENSE(MODULE_LIC);
MODULE_SUPPORTED_DEVICE();



