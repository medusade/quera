########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 1/14/2018
#
# Thirdpary Makefile for nadir
########################################################################

########################################################################
#
# nadir defs
#
########################################################################
NADIR_MAKEDIR=$(PWD)

NADIR_THIRDPARTY = $(NADIR_MAKEDIR)/..
#NADIR_BUILD_HOME = $(NADIR_THIRDPARTY)

ifndef NADIR_UNAME
NADIR_UNAME = $(shell uname)
endif

ifndef NADIR_OS
ifneq ($(NADIR_UNAME), Darwin)
NADIR_OS = linux
else
NADIR_OS = macosx
endif
endif

#
# nadir version
#
NADIR_VERSION_MAJOR = 1
NADIR_VERSION_MINOR = 1
NADIR_VERSION_RELEASE = 1

NADIR_VERSION_SEPARATOR = .
NADIR_VERSION_MAJOR_SEPARATOR = $(NADIR_VERSION_SEPARATOR)
NADIR_VERSION_MINOR_SEPARATOR = $(NADIR_VERSION_SEPARATOR)

NADIR_VERSION_SHORT = $(NADIR_VERSION_MAJOR)$(NADIR_VERSION_MINOR)$(NADIR_VERSION_RELEASE)
NADIR_VERSION = $(NADIR_VERSION_MAJOR)$(NADIR_VERSION_MAJOR_SEPARATOR)$(NADIR_VERSION_MINOR)$(NADIR_VERSION_MINOR_SEPARATOR)$(NADIR_VERSION_RELEASE)

#
# nadir name
#
NADIR_NAME_SEPARATOR = -
NADIR_NAME_BASE = nadir
NADIR_NAME = $(NADIR_NAME_BASE)$(NADIR_NAME_SEPARATOR)$(NADIR_VERSION)
NADIR_INSTALL_NAME_SEPARATOR = -
NADIR_INSTALL_NAME = $(NADIR_NAME_BASE)$(NADIR_INSTALL_NAME_SEPARATOR)$(NADIR_VERSION)
NADIR_DIR = $(NADIR_NAME)

#
# nadir archive
#
NADIR_ARCHIVED = tar
NADIR_COMPRESSED = gz
NADIR_ARCHIVE_SEPARATOR = .
NADIR_ARCHIVED_SEPARATOR = $(NADIR_ARCHIVE_SEPARATOR)
NADIR_COMPRESSED_SEPARATOR = $(NADIR_ARCHIVE_SEPARATOR)

NADIR_EXTRACT_DIR = $(NADIR_NAME)
NADIR_TGZ_PREFIX = 
NADIR_TGZ = $(NADIR_NAME)$(NADIR_TGZ_PREFIX)$(NADIR_ARCHIVED_SEPARATOR)$(NADIR_ARCHIVED)$(NADIR_COMPRESSED_SEPARATOR)$(NADIR_COMPRESSED)
NADIR_PATCH_TGZ_PREFIX = $(NADIR_NAME_SEPARATOR)patch
NADIR_PATCH_TGZ = $(NADIR_NAME)$(NADIR_PATCH_TGZ_PREFIX)$(NADIR_ARCHIVED_SEPARATOR)$(NADIR_ARCHIVED)$(NADIR_COMPRESSED_SEPARATOR)$(NADIR_COMPRESSED)
NADIR_DOCS_TGZ_PREFIX = $(NADIR_NAME_SEPARATOR)docs
NADIR_DOCS_TGZ = $(NADIR_NAME)$(NADIR_DOCS_TGZ_PREFIX)$(NADIR_ARCHIVED_SEPARATOR)$(NADIR_ARCHIVED)$(NADIR_COMPRESSED_SEPARATOR)$(NADIR_COMPRESSED)

#
# nadir extract
#
ifeq ($(NADIR_ARCHIVED),tar)
ifeq ($(NADIR_COMPRESSED),gz)
NADIR_TAR_UNCOMPRESS = z
NADIR_TAR_COMPRESS = z
else
ifeq ($(NADIR_COMPRESSED),bz2)
NADIR_TAR_UNCOMPRESS = j
NADIR_TAR_COMPRESS = j
else
ifeq ($(NADIR_COMPRESSED),xz)
NADIR_TAR_UNCOMPRESS = J
NADIR_TAR_COMPRESS = J
else
endif
endif
endif
NADIR_LIST = tar -tv$(NADIR_TAR_UNCOMPRESS)f
NADIR_EXTRACT = tar -x$(NADIR_TAR_UNCOMPRESS)f
NADIR_ARCHIVE = tar -cv$(NADIR_TAR_COMPRESS)f
else
ifeq ($(NADIR_ARCHIVED),zip)
NADIR_LIST = unzip -l
NADIR_EXTRACT = unzip
NADIR_ARCHIVE = zip
else
NADIR_LIST = echo unable to list
NADIR_EXTRACT = echo unable to extract
NADIR_ARCHIVE = echo unable to archive
endif
endif

NADIR_LIST_TGZ = $(NADIR_LIST) $(NADIR_TGZ)
NADIR_EXTRACT_TGZ = $(NADIR_EXTRACT) $(NADIR_TGZ)
NADIR_TOUCH_EXTRACT = touch $(NADIR_DIR)
NADIR_REMOVE_DIR = $(NADIR_REMOVE) $(NADIR_DIR)

NADIR_LIST_PATCH = $(NADIR_LIST)
NADIR_EXTRACT_PATCH = $(NADIR_EXTRACT)
NADIR_LIST_PATCH_TGZ = $(NADIR_LIST_PATCH) $(NADIR_PATCH_TGZ)
NADIR_EXTRACT_PATCH_TGZ = $(NADIR_EXTRACT_PATCH) $(NADIR_PATCH_TGZ)

NADIR_LIST_DOCS = $(NADIR_LIST)
NADIR_EXTRACT_DOCS = $(NADIR_EXTRACT)
NADIR_LIST_DOCS_TGZ = $(NADIR_LIST_DOCS) $(NADIR_DOCS_TGZ)
NADIR_EXTRACT_DOCS_TGZ = $(NADIR_EXTRACT_DOCS) $(NADIR_DOCS_TGZ) -C$(NADIR_DOCS_PREFIX)

#
# nadir build
#
ifndef NADIR_BUILD_HOME
NADIR_BUILD = $(HOME)/build
else
NADIR_BUILD = $(NADIR_BUILD_HOME)/build
endif
NADIR_PREFIX = $(NADIR_BUILD)/$(NADIR_INSTALL_NAME)
NADIR_EXEC_PREFIX = $(NADIR_PREFIX)
NADIR_CONF_PREFIX = $(NADIR_PREFIX)
NADIR_DOCS_PREFIX = $(NADIR_PREFIX)
NADIR_LINK_NAME = $(NADIR_BUILD)/$(NADIR_NAME_BASE)

NADIR_MKDIR = mkdir -p
NADIR_REMOVE = rm -r -f

NADIR_MAKE_DIR = $(NADIR_DIR)
NADIR_MAKE_PUSHD = pushd $(NADIR_MAKE_DIR)
NADIR_MAKE = make

#
# nadir configure
#
ifneq ($(NADIR_UNAME), Darwin)
NADIR_CONFIGURE_UNAME = 
else
NADIR_CONFIGURE_UNAME = 
endif
NADIR_CONFIGURE_CONFIGURE = ./configure
NADIR_CONFIGURE_HELP = $(NADIR_CONFIGURE_CONFIGURE) --help
NADIR_CONFIGURE_PUSHD = pushd $(NADIR_MAKE_DIR)
NADIR_CONFIGURE = $(NADIR_CONFIGURE_CONFIGURE) \
$(NADIR_CONFIGURE_UNAME) --prefix=$(NADIR_PREFIX) --exec_prefix=$(NADIR_EXEC_PREFIX)

#
# nadir help
#
NADIR_HELP = $(NADIR_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: build

package: archive unextract

again: unextract build

test: test-nadir

install-links: install-nadir-links

install-docs: install-nadir-docs

install-prefix: install-nadir-prefix

install: install-nadir

build: build-nadir

clean: clean-nadir

configed: configed-$(NADIR_DIR)

config: config-$(NADIR_DIR)

help: help-nadir

list-docs: list-nadir-docs

list-patch: list-nadir-patch

extract-patch: extract-nadir-patch

list: list-nadir

extract: extract-nadir

unextract: unextract-nadir

archive: archive-nadir

linked: nadir-linked

prefixed: nadir-prefixed

archived: nadir-archived

extracted: nadir-extracted

########################################################################
#
# nadir rules
#
########################################################################

#
# Help nadir
#
help-nadir: $(NADIR_DIR)
	@($(NADIR_CONFIGURE_PUSHD);\
	  (($(NADIR_HELP)) || (exit 1));\
	  popd)

#
# Install nadir
#
install-nadir: configed-$(NADIR_DIR)
	@(echo Installing $(NADIR_DIR)...;\
	  $(NADIR_MAKE_PUSHD);\
	  (($(NADIR_MAKE) install) || (exit 1)) && \
	  ((touch $(NADIR_MAKEDIR)/configed-$(NADIR_DIR)) || (exit 1));\
	  popd)
	  
#
# Build nadir
#
build-nadir: configed-$(NADIR_DIR)
	@(echo Building $(NADIR_DIR)...;\
	  $(NADIR_MAKE_PUSHD);\
	  (($(NADIR_MAKE)) || (exit 1)) && \
	  ((touch $(NADIR_MAKEDIR)/configed-$(NADIR_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean nadir
#
clean-nadir: configed-$(NADIR_DIR)
	@(echo Cleaning $(NADIR_DIR)...;\
	  $(NADIR_MAKE_PUSHD);\
	  (($(NADIR_MAKE) clean) || (exit 1)) && \
	  ((touch $(NADIR_MAKEDIR)/configed-$(NADIR_DIR)) || (exit 1));\
	  popd)
	  
#
# Test nadir
#
test-nadir: configed-$(NADIR_DIR)
	@(echo Building test $(NADIR_DIR)...;\
	  $(NADIR_MAKE_PUSHD);\
	  (($(NADIR_MAKE) test) || (exit 1)) && \
	  ((touch $(NADIR_MAKEDIR)/configed-$(NADIR_DIR)) || (exit 1));\
	  popd)
	  
#
# Config nadir
#
config-$(NADIR_DIR): unconfig-$(NADIR_DIR) configed-$(NADIR_DIR)

unconfig-$(NADIR_DIR):
	@(rm -f configed-$(NADIR_DIR))

configed-$(NADIR_DIR): $(NADIR_DIR)
	@(echo Configing $(NADIR_DIR)...;\
	  $(NADIR_CONFIGURE_PUSHD);\
	  (($(NADIR_CONFIGURE)) || (exit 1)) && \
	  ((touch $(NADIR_DIR)) || (exit 1)) && \
	  ((touch $(NADIR_MAKEDIR)/configed-$(NADIR_DIR)) || (exit 1));\
	  popd)

########################################################################
# docs
########################################################################

#
# List nadir Docs
#
list-nadir-docs: $(NADIR_DOCS_TGZ)
	@(echo Listing $(NADIR_DOCS_TGZ)...;\
	  (($(NADIR_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install nadir Docs
#
install-nadir-docs: $(NADIR_DOCS_PREFIX)
	@(echo Extracting $(NADIR_DOCS_TGZ)...;\
	  (($(NADIR_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
# patch
########################################################################

#
# List nadir Patch
#
list-nadir-patch: $(NADIR_PATCH_TGZ)
	@(echo Listing $(NADIR_PATCH_TGZ)...;\
	  (($(NADIR_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract nadir patch
#
extract-nadir-patch: $(NADIR_DIR)
	@(echo Extracting $(NADIR_PATCH_TGZ)...;\
	  (($(NADIR_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
# archive
########################################################################

#
# List nadir
#
list-nadir: 
	@(echo Listing $(NADIR_TGZ)...;\
	  (($(NADIR_LIST_TGZ)) || (exit 1)))

#
# nadir extracted
#
nadir-extracted: 
	@(echo $(NADIR_EXTRACT) $(NADIR_TGZ))

#
# Extract nadir
#
extract-nadir: unextract-nadir $(NADIR_DIR)

unextract-nadir: unconfig-$(NADIR_DIR)
	@(echo Removing $(NADIR_DIR)...;\
	  (($(NADIR_REMOVE_DIR)) || (exit 1)))

$(NADIR_DIR): $(NADIR_TGZ)
	@(echo Extracting $(NADIR_TGZ)...;\
	  (($(NADIR_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(NADIR_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# nadir archived
#
nadir-archived: 
	@(echo $(NADIR_TGZ))
	  
#
# Archive nadir
#
archive-nadir: 
	@(echo Archiving $(NADIR_DIR) to $(NADIR_TGZ)...;\
	  (($(NADIR_ARCHIVE) $(NADIR_TGZ) $(NADIR_DIR)) || (exit 1)))

########################################################################
# links
########################################################################

#
# nadir linked
#
nadir-linked: 
	@echo link is $(NADIR_LINK_NAME) "->" $(NADIR_PREFIX)
	  
#
# Install nadir links
#
install-nadir-links: 
	@((echo removing $(NADIR_LINK_NAME)) && \
	  ((rm -f $(NADIR_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(NADIR_LINK_NAME) "->" $(NADIR_PREFIX)) && \
	  ((ln -s $(NADIR_PREFIX) $(NADIR_LINK_NAME)) || (exit 1)))
	  
########################################################################
# prefix
########################################################################

#
# nadir prefixed
#
nadir-prefixed: 
	@((echo prefix is $(NADIR_PREFIX)) && \
	  (echo exec prefix is $(NADIR_EXEC_PREFIX)) && \
	  (echo conf prefix is $(NADIR_CONF_PREFIX)) && \
	  (echo docs prefix is $(NADIR_DOCS_PREFIX)))
	  
#
# Install nadir prefix
#
install-nadir-prefix: 
	@((echo makeing $(NADIR_PREFIX)) && \
	  ((mkdir -p $(NADIR_PREFIX)) || (exit 1)) && \
	  (echo makeing $(NADIR_EXEC_PREFIX)) && \
	  ((mkdir -p $(NADIR_EXEC_PREFIX)) || (exit 1)))
	  
$(NADIR_PREFIX):
	@(echo Makeing Directory $(NADIR_PREFIX)...;\
	  (($(NADIR_MKDIR) $(NADIR_PREFIX)) || (exit 1)))

$(NADIR_EXEC_PREFIX):
	@(echo Makeing Directory $(NADIR_EXEC_PREFIX)...;\
	  (($(NADIR_MKDIR) $(NADIR_EXEC_PREFIX)) || (exit 1)))

$(NADIR_CONF_PREFIX):
	@(echo Makeing Directory $(NADIR_CONF_PREFIX)...;\
	  (($(NADIR_MKDIR) $(NADIR_CONF_PREFIX)) || (exit 1)))

$(NADIR_DOCS_PREFIX):
	@(echo Makeing Directory $(NADIR_DOCS_PREFIX)...;\
	  (($(NADIR_MKDIR) $(NADIR_DOCS_PREFIX)) || (exit 1)))




        

