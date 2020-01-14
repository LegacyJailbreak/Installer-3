//AppTapp Installer Writer by lex
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include <libxml/xmlwriter.h>
#include <string.h>
#include <stdio.h>

xmlTextWriterPtr writer;
char bundleIdentifier[1024];
char name[1024];
char version[1024];
char size[1024];
char location[1024];
char url[1024];
char time[1024];
char category[1024];
char description[1024];
char copypathinstallfilepath[1024];
char copypathsourcefilepath[1024];
char removepathinstalledfilepath[1024];

int main(){
	
	printf("Enter BundleID:\n");
	scanf(" %1024[^\n]", bundleIdentifier);
	printf("Enter Name:\n");
 	scanf(" %1024[^\n]", name);
	printf("Enter Version:\n");
	scanf(" %1024[^\n]", version);
	printf("Enter Size:\n");
	scanf(" %1024[^\n]", size);
	printf("Enter Location:\n");
	scanf(" %1024[^\n]", location);
	printf("Enter URL:\n");
	scanf(" %1024[^\n]", url);
	printf("Enter Category:\n");
	scanf(" %1024[^\n]", category);
	printf("Enter Description:\n");
	scanf(" %1024[^\n]", description);
	printf("Enter Unix Time:\n");
	scanf(" %1024[^\n]", time);
	
    writer = xmlNewTextWriterFilename("i3.xml", 0);

        xmlTextWriterSetIndent(writer,1);


        xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"bundleIdentifier");
        xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)bundleIdentifier);
	
	xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"name");
	xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)name);
	
	xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"version");
	xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)version);
	
	xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"size");
	xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)size);
	
	xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"location");
	xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)location);

	xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"url");
	xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)url);
	
	xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"description");
	xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)description);
	
	xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"scripts");
	
	

		xmlTextWriterStartElement(writer,(xmlChar *)"dict");
	
		
		xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"install");
		
		xmlTextWriterStartElement(writer,(xmlChar *)"array");
		
	
	

	
	char copypathanswer;
	printf("\nWould you like to add a CopyPath? Enter (y/n): \n");
	scanf(" %c", &copypathanswer);
	printf("\n answer is %c\n", copypathanswer);
	while (copypathanswer == 'y'){
		
		xmlTextWriterStartElement(writer,(xmlChar *)"array");
		xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)"CopyPath");
		

		
			
			printf("Enter file or directory in package:\n");
			scanf(" %1024[^\n]", copypathsourcefilepath);
		
		printf("Enter install path of previous file or directory in package:\n");
		scanf(" %1024[^\n]", copypathinstallfilepath);
			
		xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)copypathsourcefilepath);
		xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)copypathinstallfilepath);

		xmlTextWriterEndElement(writer);
	printf("\nWould you like to add another CopyPath? Enter (y/n): \n");
		
		scanf(" %c", &copypathanswer);
		printf("\n answer is %c\n", copypathanswer);
		
	}
	
				xmlTextWriterEndElement(writer);
	
		xmlTextWriterWriteElement(writer,(xmlChar *)"key",(xmlChar *)"Uninstall");
	  xmlTextWriterStartElement(writer,(xmlChar *)"array");
	
	
	
	
	
	char removepathanswer;
	printf("\nWould you like to add a RemovePath? Enter (y/n): \n");
	scanf(" %c", &removepathanswer);
	printf("\n answer is %c\n", removepathanswer);
	while (removepathanswer == 'y'){

		xmlTextWriterStartElement(writer,(xmlChar *)"array");
		xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)"RemovePath");
		
		printf("Enter install path of previous file or directory in package:\n");
		scanf(" %1024[^\n]", removepathinstalledfilepath);
		
	char removeanotherpathanswer;
		printf("\nWould you like to remove another path with RemovePath? Enter (y/n): \n");
		scanf(" %c", &removeanotherpathanswer);
		printf("\n answer is %c\n", removeanotherpathanswer);
		while (removeanotherpathanswer == 'y'){
			
		printf("Enter install path of previous file or directory in package:\n");
		scanf(" %1024[^\n]", removepathinstalledfilepath);
		
		xmlTextWriterWriteElement(writer,(xmlChar *)"string", (xmlChar *)removepathinstalledfilepath);

		printf("\nWould you like to remove another path with RemovePath? Enter (y/n): \n");
			scanf(" %c", &removeanotherpathanswer);
			printf("\n answer is %c\n", removeanotherpathanswer);
		}
		
		xmlTextWriterEndElement(writer);
		printf("\nWould you like to add another RemovePath? Enter (y/n): \n");
		
		scanf(" %c", &removepathanswer);
		printf("\n answer is %c\n", removepathanswer);
		
	}
	xmlTextWriterEndElement(writer);

        xmlTextWriterEndElement(writer);
        xmlTextWriterEndElement(writer);
        xmlTextWriterEndDocument(writer);
        xmlFreeTextWriter(writer);
  
exit(0);
}
